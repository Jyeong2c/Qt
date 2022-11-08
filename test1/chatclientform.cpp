#include "chatclientform.h"

#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDataStream>
#include <QTcpSocket>
#include <QApplication>
#include <QThread>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QProgressDialog>
#include <QComboBox>

#define BLOCK_SIZE      1024

ChatClientForm::ChatClientForm(QWidget *parent) : QWidget(parent), isSent(false) {
    // 연결한 서버 정보 입력을 위한 위젯들
    name = new QLineEdit(this);                             //이름을 입력하는 처음 lineEdit
    QSettings settings("ChatClient", "Chat Client");        //키하고 벨류값으로 파일이 저장이 된다
    //name->setText(settings.value("ChatClient/ID").toString());      //안써도 된다

    serverAddress = new QLineEdit(this);                    //주소 lineEdit
    serverAddress->setText("127.0.0.1");                    //기본값 설정
    //serverAddress->setInputMask("999.999.999.999;_");
    QRegularExpression re("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegularExpressionValidator validator(re);
    serverAddress->setPlaceholderText("Server IP Address");
    serverAddress->setValidator(&validator);

    //포트 번호
    serverPort = new QLineEdit(this);                       //세번째 lienEdit port
    serverPort->setText(QString::number(PORT_NUMBER));      //기본 포트 8000번대
    serverPort->setInputMask("00000;_");
    serverPort->setPlaceholderText("Server Port No");

    connectButton = new QPushButton(tr("Log In"), this);    //버튼을 Log In 이라고 설정

    QHBoxLayout *serverLayout = new QHBoxLayout;        //위젯 설정 레이아웃
    serverLayout->addWidget(name);                      //이름
    serverLayout->addStretch(1);
    serverLayout->addWidget(serverAddress);             //주소
    serverLayout->addWidget(serverPort);                //포트
    serverLayout->addWidget(connectButton);             //버튼

    message = new QTextEdit(this);                      // 서버에서 오는 메시지 표시용
    message->setReadOnly(true);                         //입력X

    // 서버로 보낼 메시지를 위한 위젯들
    inputLine = new QLineEdit(this);                    //input 서버로 보낼 lineEdit
    connect(inputLine, SIGNAL(returnPressed( )), SLOT(sendData( )));          //enter를 치면 sendData를 보냄
    connect(inputLine, SIGNAL(returnPressed( )), inputLine, SLOT(clear( )));  //inputLine을 clear
    sentButton = new QPushButton("Send", this);                               //sent 버튼
    connect(sentButton, SIGNAL(clicked( )), SLOT(sendData( )));               //클릭하면 데이터보냄
    connect(sentButton, SIGNAL(clicked( )), inputLine, SLOT(clear( )));       //lineEdit 지움
    inputLine->setDisabled(true);                                             //lineEdit 입력 불가
    sentButton->setDisabled(true);                                            //sent버튼 사용불가

    QHBoxLayout *inputLayout = new QHBoxLayout;                     //input lineEdit과 버튼을 레이아웃
    inputLayout->addWidget(inputLine);
    inputLayout->addWidget(sentButton);

    fileButton = new QPushButton("File Transfer", this);            //file 전송 Button 레이아웃
    connect(fileButton, SIGNAL(clicked( )), SLOT(sendFile( )));     //파일전송 버튼 클릭시 파일 전송
    fileButton->setDisabled(true);                                  //버튼 사용 불가

    // 종료 기능
    QPushButton* quitButton = new QPushButton("Log Out", this);
    connect(quitButton, SIGNAL(clicked( )), this, SLOT(close( )));  //Log Out 버튼을 눌리면 창을 닫는다.

    QHBoxLayout *buttonLayout = new QHBoxLayout;                    //파일전송 버튼과 종료 버튼 레이아웃
    buttonLayout->addWidget(fileButton);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);                //위젯과 레이아웃들을 VBOX로 레이아웃
    mainLayout->addLayout(serverLayout);
    mainLayout->addWidget(message);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    /* 채팅을 위한 소켓 */                                                     //서버와 연결 할 소켓 8000번
    clientSocket = new QTcpSocket(this);                                    // 클라이언트 소켓 생성
    connect(clientSocket, &QAbstractSocket::errorOccurred,
            [=]{ qDebug( ) << clientSocket->errorString( ); });
    connect(clientSocket, SIGNAL(readyRead( )), SLOT(receiveData( )));  //데이터가 읽을준비가 되면 데이터를 받음
    connect(clientSocket, SIGNAL(disconnected( )), SLOT(disconnect( )));

    /* 파일 전송을 위한 소켓 */      //8001번에 접속
    fileClient = new QTcpSocket(this);                 //데이터를 처음에 조금 보내고 다음 데이터 보낼 때 보낸다
    connect(fileClient, SIGNAL(bytesWritten(qint64)), SLOT(goOnSend(qint64)));
    connect(fileClient, SIGNAL(disconnected( )), fileClient, SLOT(deletelater( )));       //나눠서 보낸다

    progressDialog = new QProgressDialog(0);        //파일 전송 프로그레스
    progressDialog->setAutoClose(true);             //파일이 자동으로 닫힘
    progressDialog->reset();                        //reset

    connect(connectButton, &QPushButton::clicked,
            [=]{
        if(connectButton->text() == tr("Log In")) {     //로그인을 눌렸을 때


            clientSocket->connectToHost(serverAddress->text( ), //호스트에 접속하고
                                        serverPort->text( ).toInt( ));
            clientSocket->waitForConnected();                   // 접속이 끝날 때 까지 기다린다
            sendProtocol(Chat_Login, name->text().toStdString().data());    //로그인을 했다고 서버에 보냄
            QString clientName =  name->text().toStdString().data();
            emit sendClientName(clientName);            //로그인할때 신호를 이름을 가진 신호를 보냄

            if(flag == 0)                               //flag가 0 이면
            {
                connectButton->setText(tr("Log In"));   // 버튼이 Log In 표시
                QMessageBox::warning(this, tr("Chatting Client"),
                                     tr("No Search Name"));                 //이름을 찾을수없다고 메세지 띄움

            }else{
                connectButton->setText(tr("Chat in"));  //버튼이 Chat in으로 바뀌고
                name->setReadOnly(true);                //이름버튼이 읽기 모드로 바뀜
            }


        } else if(connectButton->text() == tr("Chat in"))  {        //Chat in 상태에서는
            sendProtocol(Chat_In, name->text().toStdString().data());   //chat In이라고 서버에 보냄
            connectButton->setText(tr("Chat Out"));                 //버튼을 Chat Out으로 바꿈
            inputLine->setEnabled(true);                            //버튼 상태들을 활성화
            sentButton->setEnabled(true);
            fileButton->setEnabled(true);
        } else if(connectButton->text() == tr("Chat Out"))  {       //Chat Out 상태에서는
            sendProtocol(Chat_Out, name->text().toStdString().data());  //Chat Out이라고 서버에 보냄
            connectButton->setText(tr("Chat in"));                  //Chat in으로 바꿈
            inputLine->setDisabled(true);                           //버튼 상태 비활설화
            sentButton->setDisabled(true);
            fileButton->setDisabled(true);
        }
    } );

    setWindowTitle(tr("Chat Client"));                              //윈도우 타이틀 설정
}

ChatClientForm::~ChatClientForm( )
{
    clientSocket->close( );                                 //소켓 연결 닫음
    QSettings settings("ChatClient", "Chat Client");        //닫을 때 이름 저장
    settings.setValue("ChatClient/ID", name->text());
}

/* 창이 닫힐 때 서버에 연결 접속 메시지를 보내고 종료 */
void ChatClientForm::closeEvent(QCloseEvent*)
{
    sendProtocol(Chat_LogOut, name->text().toStdString().data());  //Chat LogOut이라고 서버에 보내고
    clientSocket->disconnectFromHost();                            //소켓 연결을 끊고
    if(clientSocket->state() != QAbstractSocket::UnconnectedState)
        clientSocket->waitForDisconnected();
}

/* 데이터를 받을 때 */
void ChatClientForm::receiveData( )                         //서버에서 데이터가 오면
{
    QTcpSocket *clientSocket = dynamic_cast<QTcpSocket *>(sender( )); //채팅관련해서 소켓을 받은 후
    if (clientSocket->bytesAvailable( ) > BLOCK_SIZE) return;   //읽을 데이터가 있으면
    QByteArray bytearray = clientSocket->read(BLOCK_SIZE);      //데이터를 읽어서 타입과 데이터를 확인

    Chat_Status type;                                           // 채팅의 목적
    char data[1020];                                            // 전송되는 메시지/데이터
    memset(data, 0, 1020);                                      // 0으로초기화 하여 읽음

    QDataStream in(&bytearray, QIODevice::ReadOnly);
    in.device()->seek(0);
    in >> type;                                                 // 패킷의 타입
    in.readRawData(data, 1020);                                 // 실제 데이터

    switch(type) {
    case Chat_Talk:         // 온 패킷의 타입이 대화이면
        //kickOut시 메세지가 보내지면 안되기 때문에 chatFlag를 이용하여 수행
        if(chatFlag == 0)                   //chatFlag 초기값이 0 이므로 처음 수행
        {
        message->append(QString(data));                         // 온메시지를 화면에 표시
        inputLine->setEnabled(true);                            //line 활성화
        sentButton->setEnabled(true);                           //sent 버튼 활성화
        fileButton->setEnabled(true);                           //file 버튼 활성화
        }
       else if(chatFlag ==1)                //kickout이 되면 chatFlag가 1이 되어 비활성화 되게 함
        {
            inputLine->setEnabled(false);                       // line 비활성화
            sentButton->setEnabled(false);                      //sent 버튼 비활성화
            fileButton->setEnabled(false);                      //file 버튼 비활성화
        }
        break;
    case Chat_KickOut:      // 강퇴
        chatFlag = 1;                        //버튼들을 비활성화 하기 위해 chatFlag 값을 1로 줌
        QMessageBox::critical(this, tr("Chatting Client"),      //강퇴시 메세지 창으로 알림설정
                              tr("Kick out from Server"));
        inputLine->setDisabled(true);                           // line 비활성화
        sentButton->setDisabled(true);                          //sent 버튼 비활성화
        fileButton->setDisabled(true);                          //file 버튼 비활성화
        name->setReadOnly(false);                               // 메시지 입력 불가
        connectButton->setText(tr("Chat In"));      //버튼창을 처음 단계인 Chat In으로 설정
        name->setDisabled(true);
        connectButton->setDisabled(true);
        break;
    case Chat_Invite:       // 초대
        chatFlag =0;
        QMessageBox::question(this, tr("Chatting Client"),      //초대시 안내창을 띄어줌
                              tr("Invited from Server"));

        inputLine->setEnabled(true);                            // line 활성화
        sentButton->setEnabled(true);                           //sent 버튼 활성화
        fileButton->setEnabled(true);                           //file 버튼 활성화
        name->setReadOnly(true);                                // 메시지 입력 가능
        connectButton->setText(tr("Chat Out"));
        name->setEnabled(true);
        connectButton->setEnabled(true);
        break;
    };
}

/* 연결이 끊어졌을 때 : 상태 변경 */
void ChatClientForm::disconnect( )
{
    QMessageBox::information(this,tr("Chatting Client"),        //안내 메세지를 메세지박스로 보여줌
                          tr("Disconnect from Server"));
    inputLine->setEnabled(false);                               // line 비활성화
    name->setReadOnly(false);                                   //name을 활성화
    sentButton->setEnabled(false);                              //sent 버튼 비활성화
    connectButton->setText(tr("Log In"));                       //버튼 창을Log In으로 설정
}

/* 프로토콜을 생성해서 서버로 전송 */
void ChatClientForm::sendProtocol(Chat_Status type, char* data, int size)
{
    QByteArray dataArray;                                       // 소켓으로 보낼 데이터를 채우고
    QDataStream out(&dataArray, QIODevice::WriteOnly);
    out.device()->seek(0);
    out << type;                                                //타입
    out.writeRawData(data, size);                               //데이터를
    clientSocket->write(dataArray);                             // 서버로 전송
    clientSocket->flush();
    while(clientSocket->waitForBytesWritten());                 //서버까지 갈 동안 기다린다 (약 3초)
}

/* 메시지 보내기 */
void ChatClientForm::sendData(  )                               //채팅 창에 데이터 보낼 때 마다 불려진다
{
    QString str = inputLine->text( );                           //데이터를 보낼 때
    if(str.length( )) {
        QByteArray bytearray;
        bytearray = str.toUtf8( );                              // 화면에 표시 : 앞에 '나'라고 추가
        message->append("<font color=red>나</font> : " + str);
        sendProtocol(Chat_Talk, bytearray.data());              //서버로 메세지를 보냄
    }
}

/* 파일 전송시 여러번 나눠서 전송 */
void ChatClientForm::goOnSend(qint64 numBytes) // Start sending file content
{   //파일을 전체를 보낼 수 없기때문에 나눠서 전송
    byteToWrite -= numBytes;                                    //보낸 만큼 byteToWrite가 감소
    outBlock = file->read(qMin(byteToWrite, numBytes));
    fileClient->write(outBlock);

    progressDialog->setMaximum(totalSize);
    progressDialog->setValue(totalSize-byteToWrite);

    if (byteToWrite == 0) {                                     //0이되면 파일 전송 완료
        qDebug("File sending completed!");
        progressDialog->reset();                                //프로그레스바가 닫힘
    }
}

/* 파일 보내기 */
void ChatClientForm::sendFile() // Open the file and get the file name (including path)
{
    loadSize = 0;
    byteToWrite = 0;
    totalSize = 0;
    outBlock.clear();

    QString filename = QFileDialog::getOpenFileName(this);
    if(filename.length()) {                                     //파일이 있으면
        file = new QFile(filename);
        file->open(QFile::ReadOnly);                            //파일을 열고

        qDebug() << QString("file %1 is opened").arg(filename);
        progressDialog->setValue(0);                            //프로그레스바를 띄운다
                                                                //서버하고 접속 안되어 있으면
        if (!isSent) {
            fileClient->connectToHost(serverAddress->text( ),
                                      serverPort->text( ).toInt( ) + 1);    //서버 포트에서 +1해서 서버와 연결
            isSent = true;
        }


        byteToWrite = totalSize = file->size();                 //파일의 크기를 열고
        loadSize = 1024;

        QDataStream out(&outBlock, QIODevice::WriteOnly);
        out << qint64(0) << qint64(0) << filename << name->text();   //totalSize , Block,file이름,이름 쓰고

        totalSize += outBlock.size();
        byteToWrite += outBlock.size();

        out.device()->seek(0);                                  //seek으로 앞으로 이동 한다
        out << totalSize << qint64(outBlock.size());            //전체 크기, 사이즈를 넣고

        fileClient->write(outBlock);                            //서버로 보낸다

        progressDialog->setMaximum(totalSize);                  //프로그레스바 최대 사이즈 설정
        progressDialog->setValue(totalSize-byteToWrite);        //최대사이즈에서 값설정을 한 후
        progressDialog->show();                                 //프로그레스바를보여줌
    }
    qDebug() << QString("Sending file %1").arg(filename);
}

void ChatClientForm::flagSended(int flag1)                      //서버에 있는 이름이 맞는지 확인하기 위한 flag
{
    flag= flag1;
}

