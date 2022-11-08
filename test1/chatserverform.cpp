#include "chatserverform.h"
#include "ui_chatserverform.h"
#include "logthread.h"

#include <QPushButton>
#include <QBoxLayout>
#include <QTcpServer>
#include <QTcpSocket>
#include <QApplication>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QDebug>
#include <QMenu>
#include <QFile>
#include <QFileInfo>
#include <QProgressDialog>

ChatServerForm::ChatServerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatServerForm), totalSize(0), byteReceived(0)
{
    ui->setupUi(this);                                                     //현재 클래스 폼에  ui를 올린다
    QList<int> sizes;
    sizes << 120 << 500;
    ui->splitter->setSizes(sizes);                                              //스프리터의 사이즈 설정

    chatServer = new QTcpServer(this);                                          //server 만듬
    connect(chatServer, SIGNAL(newConnection( )), SLOT(clientConnect( )));      //clientConnect 을 부름
    //주소 및 포트에서 챗 서버로 들어오는 연결이 Ipv4, IPv6, 포트 번호(8000)가 아니면
    if (!chatServer->listen(QHostAddress::Any, PORT_NUMBER)) {
        QMessageBox::critical(this, tr("Chatting Server"),                      //경고 메세지 출력
                              tr("Unable to start the server: %1.")
                              .arg(chatServer->errorString( )));
        return;
    }

    // chatserver와 fileServer를 분리 파일이 전송될때도 채팅이 되게 분리화
    fileServer = new QTcpServer(this);
    connect(fileServer, SIGNAL(newConnection()), SLOT(acceptConnection()));     //acceptConnection을 부르
    //주소 및 포트에서 파일서버로 들어오는 연결이 Ipv4, IPv6, 포트 번호(8000+1)이 아니면
    if (!fileServer->listen(QHostAddress::Any, PORT_NUMBER+1)) {
        QMessageBox::critical(this, tr("Chatting Server"),
                              tr("Unable to start the server: %1.")             //경고 메세지 출력
                              .arg(fileServer->errorString( )));
        return;
    }

    qDebug("Start listening ...");

    QAction* inviteAction = new QAction(tr("&Invite"));                         //초대 액션
    inviteAction->setObjectName("Invite");                                      //초대 액션 제목
    connect(inviteAction, SIGNAL(triggered()), SLOT(inviteClient()));           //triggered시 초대

    QAction* removeAction = new QAction(tr("&Kick out"));                       //강퇴 액션
    connect(removeAction, SIGNAL(triggered()), SLOT(kickOut()));                //triggered시 강퇴

    menu = new QMenu;                                                            //메뉴 생성
    menu->addAction(inviteAction);                                               //메뉴에 초대 액션 추가
    menu->addAction(removeAction);                                               //메뉴에 강퇴 액션 추가
    ui->clientTreeWidget->setContextMenuPolicy(Qt::CustomContextMenu);           //메뉴얼 정책

    progressDialog = new QProgressDialog(0);                                     //프로그래스다이어로그 생성
    progressDialog->setAutoClose(true);                                          //reset하면 자동으로 닫힌다
    progressDialog->reset();                                                     //리셋

    logThread = new LogThread(this);                                             //로그를 스레드 기반으로 만듬
    logThread->start();                                                          //로그 시작

    connect(ui->savePushButton, SIGNAL(clicked()), logThread, SLOT(saveData())); //save버튼 눌리면 로그 스레스에 데이터 저장
    //connect(ui->clearPushButton,SIGNAL(clicked(),SLOT()))
    qDebug() << tr("The server is running on port %1.").arg(chatServer->serverPort( ));
}

ChatServerForm::~ChatServerForm()                                                //소멸자
{
    delete ui;

    logThread->terminate();                                                      //스레드 종료
    chatServer->close( );                                                        //chatServer 닫기
    fileServer->close( );                                                        //fileServer 닫기
}

void ChatServerForm::clientConnect( )
{
    QTcpSocket *clientConnection = chatServer->nextPendingConnection( );         //
    connect(clientConnection, SIGNAL(readyRead( )), SLOT(receiveData( )));       //데이터가 오면 데이터를 받으면 된다
    connect(clientConnection, SIGNAL(disconnected( )), SLOT(removeClient()));    //연결이 끊기면 X 로 처리해야하기 때문에
    qDebug("new connection is established...");
}

void ChatServerForm::receiveData( )                                              //데이터를 받기위한 함수
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender( ));    //clientConnection 가 clientConeection이 같다
    QByteArray bytearray = clientConnection->read(BLOCK_SIZE);                  //현재 server와 연결된  socket,

    Chat_Status type;                                                           // 채팅의 목적
    char data[1020];                                                            // 전송되는 메시지/데이터
    memset(data, 0, 1020);                                                      //쓰레기값이 들어가니깐 초기화

    QDataStream in(&bytearray, QIODevice::ReadOnly);
    in.device()->seek(0);                                                       //처음 부터 읽는다
    in >> type;                                                                 //type(4byte) - 채팅의 목적
    in.readRawData(data, 1020);                             //1024바이트에서 type의 4바이트를 뺀 1020바이트 만큼 메세지를 읽는다

    QString ip = clientConnection->peerAddress().toString();         //연결 되었을 때 해당 address, ip에 대입
    quint16 port = clientConnection->peerPort();                     //연결 되었을 때 해당 prot , port에 대입
    QString name = QString::fromStdString(data);                     //연결 되었을 때 해당 data, name에 대입

    qDebug() << ip << " : " << type;

    switch(type) {

    case Chat_Login:
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchFixedString, 1)){     //Item을 찾는다
            if(item->text(0) != "-") {                                          //-이 아니면
                item->setText(0, "-");                                          //-로 바꿈
            }               //name이

            clientSocketHash[name] = clientConnection;                          //name에 clientSocket을 연결
        }
        break;

    case Chat_In:
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchFixedString, 1)) {    //Item을 찾는다
            if(item->text(0) != "O") {                                          //o이 아니면
                item->setText(0, "O");                                          //o로 바뀜
            }
            clientNameHash[port] = name;
            if(clientSocketHash.contains(name))
                clientSocketHash[name] = clientConnection;
        }
        break;
    case Chat_Talk: {
        foreach(QTcpSocket *sock, clientSocketHash.values()) {  //소켓을 가져오고, 나를 제외한 모든 사람들에게 메세지를 보내야한다
            qDebug() << sock->peerPort();
            if(clientNameHash.contains(sock->peerPort()) && port != sock->peerPort()) {
                QByteArray sendArray;                           //보내는 사람을 제외한 모든 사람들에게 보내주는 메세지
                sendArray.clear();
                QDataStream out(&sendArray, QIODevice::WriteOnly);               //오직 쓰기만 수행
                out << Chat_Talk;                                                //메세지를 보냄
                sendArray.append("<font color=lightsteelblue>");                 //메세지 컬러 설정
                sendArray.append(clientNameHash[port].toStdString().data());     //해당 포트 이름
                sendArray.append("</font> : ");                                  //메세지와 구분하기 위해 : 을 사용
                sendArray.append(name.toStdString().data());                     //데이터를 보냄
                sock->write(sendArray);
                qDebug() << sock->peerPort();
            }
        }

        //로그 남기는것
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->messageTreeWidget);      //로그 남기기 위해 treeWidget 생성
        item->setText(0, ip);                                                    //ip 남김
        item->setText(1, QString::number(port));                                 //포트 번호
        item->setText(2, QString::number(clientIDHash[clientNameHash[port]]));   //고객 id 포트번호
        item->setText(3, clientNameHash[port]);                                  //고객이름
        item->setText(4, QString(data));                                         //메세지
        item->setText(5, QDateTime::currentDateTime().toString());               //메세지보낸 시간
        item->setToolTip(4, QString(data));                                      //tooltip을 보여준다
        ui->messageTreeWidget->addTopLevelItem(item);

        for(int i = 0; i < ui->messageTreeWidget->columnCount(); i++)            //메세지트리위젯을 반복하면서
            ui->messageTreeWidget->resizeColumnToContents(i);                    //크기 조정합니다
        logThread->appendData(item);                                             //로그를 기억하기 위해서 data를 append를 한다
    }
        break;
    case Chat_Out:
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchContains, 1)) {   //정보를 찾으면
            if(item->text(0) != "-") {                                           //0 번째 자리의 값이  - 이 아니면
                item->setText(0, "-");                                           //0 번째 자리의 값을 -로 설정
            }
            clientNameHash.remove(port);                                         //해당 포트를 제거한다
        }
        break;
    case Chat_LogOut:
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchContains, 1)) {   //정보를 찾고
            if(item->text(0) != "X") {                                            //0 번째 자리가 X 가 아니연
                item->setText(0, "X");                                            //0 번째 자리에 X 로 설정
            }
            clientSocketHash.remove(name);                                        //해당 이름을 제거
        }
        break;
    }
}

void ChatServerForm::removeClient()                                               //server 가 종료되면 불린다
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender( ));
    if(clientConnection != nullptr) {                                 //클라이언트 커넥터가 nullptr이 아니면
        QString name = clientNameHash[clientConnection->peerPort()];
        foreach(auto item, ui->clientTreeWidget->findItems(name, Qt::MatchContains, 1)) {   //name에 있는 값 바꿈
            item->setText(0, "X");                                    //0번째 자리 값을 X 로 설정
        }
        clientSocketHash.remove(name);                                //해당이름 제거
        clientConnection->deleteLater();                              //server에서 올 데이터가 남아있어서 deleteLater를 사용한다
    }
}
void ChatServerForm::removeClientList(int i)                          //클라이트에서 정보가 제거되면
{
    ui->clientTreeWidget->takeTopLevelItem(i);                        //클라이언트 정보를 제거
}
void ChatServerForm::modifyClientList(int key,int index, QString name)  //클라이언트폼에서 정보가 변경 될 때
{
    ui->clientTreeWidget->topLevelItem(index)->setText(1,name);        //해당 정보를 찾아 변경 함
    clientIDHash[name] = key;                                          //

}
void ChatServerForm::addClient(int id, QString name)                   //고객정보에서 정보를 가져와 clientTreeWidget에 추가
{
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->clientTreeWidget);  //clientTreeWidget 생성
    item->setText(0, "X");                                              //0번째 자리에 처음에는 아무것도 없으니깐 X 로 표시
    item->setText(1, name);                                             //1번째 자리에 이름 설정
    ui->clientTreeWidget->addTopLevelItem(item);                        //clientTreeWidget에 추가
    clientIDHash[name] = id;                                            //
    ui->clientTreeWidget->resizeColumnToContents(0);                    //
}

void ChatServerForm::on_clientTreeWidget_customContextMenuRequested(const QPoint &pos)
{
    foreach(QAction *action, menu->actions()) {
        if(ui->clientTreeWidget->currentItem() != nullptr)
        {
            if(action->objectName() == "Invite")                        // 초대
                action->setEnabled(ui->clientTreeWidget->currentItem()->text(0) != "O");
            else                                                        // 강퇴
                action->setEnabled(ui->clientTreeWidget->currentItem()->text(0) == "O");
        }
    }
    QPoint globalPos = ui->clientTreeWidget->mapToGlobal(pos);          //마우스 위치 설정
    menu->exec(globalPos);
}


void ChatServerForm::kickOut()                                          //client 강퇴하기
{
    QByteArray sendArray;
    QDataStream out(&sendArray, QIODevice::WriteOnly);                  //쓰기 모드
    out << Chat_KickOut;                                                //
    out.writeRawData("", 1020);                                         //

    if(ui->clientTreeWidget->currentItem() != nullptr)                  //현재값이 있으면
    {
        QString name = ui->clientTreeWidget->currentItem()->text(1);    //clientTreeWidget에 있는 name으로
        QTcpSocket* sock = clientSocketHash[name];                      //이름으로 소켓을 찾는다 통신은 무조건 소켓으로 하기때문에
        sock->write(sendArray);                                         //kick out을 보내준다

        ui->clientTreeWidget->currentItem()->setText(0, "-");           //clientTreeWidget의 값을 변경 시킴
        //clientSocketHash.;//name);        //다시 invite했을 때 죽는 오류
    }
}


void ChatServerForm::inviteClient()                                      //클라이언트 초대하기
{
    QByteArray sendArray;
    QDataStream out(&sendArray, QIODevice::WriteOnly);
    out << Chat_Invite;
    out.writeRawData("", 1020);

    if(ui->clientTreeWidget->currentItem() != nullptr)
    {
        /* 소켓은 현재 선택된 아이템에 표시된 이름과 해쉬로 부터 가져온다. */
        QString name = ui->clientTreeWidget->currentItem()->text(1);
        QTcpSocket* sock = clientSocketHash[name];
        if(sock == nullptr)                                              //소켓이 없으면 return
        {
            return ;
        }
        sock->write(sendArray);

        ui->clientTreeWidget->currentItem()->setText(0, "O");
        quint16 port = sock->peerPort();
        clientNameHash[port] = name;
    }
}

/* 파일 전송을 위한 소켓 생성 */
void ChatServerForm::acceptConnection()
{
    qDebug("Connected, preparing to receive files!");

    QTcpSocket* receivedSocket = fileServer->nextPendingConnection();
    connect(receivedSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
}

/* 파일 전송 */
void ChatServerForm::readClient()
{
    qDebug("Receiving file ...");
    QTcpSocket* receivedSocket = dynamic_cast<QTcpSocket *>(sender( ));
    QString filename, name;

    if (byteReceived == 0) {                                // 파일 전송 시작 : 파일에 대한 정보를 이용해서 QFile 객체 생성
        progressDialog->reset();                                            // 프로그레스다이얼로그 값을 리셋
        progressDialog->show();                                             // 프로그레스다이얼로그 보여줌

        QString ip = receivedSocket->peerAddress().toString();              //
        quint16 port = receivedSocket->peerPort();                          //
        qDebug() << ip << " : " << port;

        QDataStream in(receivedSocket);
        in >> totalSize >> byteReceived >> filename >> name;
        progressDialog->setMaximum(totalSize);                              //바를 설정

        QTreeWidgetItem* item = new QTreeWidgetItem(ui->messageTreeWidget); //무언가가 오면 로그 추가
        item->setText(0, ip);                                               //ip추가
        item->setText(1, QString::number(port));                            //포트번호 추가
        item->setText(2, QString::number(clientIDHash[name]));              //해쉬에서 찾은 이름 추가
        item->setText(3, name);                                             //이름 추가
        item->setText(4, filename);                                         //파일 이름 추가
        item->setText(5, QDateTime::currentDateTime().toString());          //현재 시간 추가
        item->setToolTip(4, filename);                                      //툴팁 추가

        /* 컨텐츠의 길이로 QTreeWidget의 헤더의 크기를 고정 */
        for(int i = 0; i < ui->messageTreeWidget->columnCount(); i++)
            ui->messageTreeWidget->resizeColumnToContents(i);

        ui->messageTreeWidget->addTopLevelItem(item);                       //messageTreeWidget에 item 추가
        logThread->appendData(item);                                        //로그스레드에 data 추가

        QFileInfo info(filename);                                           //파일이 열수 있는지 확인
        QString currentFileName = info.fileName();                          //경로에서 이름만 뽑아온다
        file = new QFile(currentFileName);                                  //현재 파일이름이 파일
        file->open(QFile::WriteOnly);                                       //파일 쓰기 모드 열기
    } else {                                                                // 파일 데이터를 읽어서 저장
        inBlock = receivedSocket->readAll();                                //데이터를 읽고 난 후
        byteReceived += inBlock.size();                                     //블락 사이즈를 더한다
        file->write(inBlock);                                               //파일에 쓰고
        file->flush();                                                      // 파일을 비움
    }

    progressDialog->setValue(byteReceived);                                 //프로그레스다이얼을 크기 만큼설정

    if (byteReceived == totalSize) {                                        //파일의 다 읽으면 QFile 객체를 닫고 삭제
        qDebug() << QString("%1 receive completed").arg(filename);

        inBlock.clear();                                                    //블락을 지움
        byteReceived = 0;                                                   //받는 바이트를 0
        totalSize = 0;                                                      //총 사이즈를 0
        progressDialog->reset();                                            //자동으로 닫힌다
        progressDialog->hide();                                             //프로그레스다이얼 숨긴다

        file->close();                                                      //파일 닫는다
        delete file;                                                        //파일 삭제
    }
}
void ChatServerForm::clientNameSended(QString clientName)            //clientTreeWidget에 있는 고객인지를 확인하기 위해
{
    int flag;
    if(ui->clientTreeWidget->findItems(clientName, Qt::MatchFixedString, 1).length() == 0)
    {                                       //chatClientForm에서 보낸 이름이 server단에 있는 고객이름과 일치하면
        flag = 0;                                                    //flag는 0
    }else{
        flag =1;                                                     //아니면 flag는 1
    }
    emit sendFlag(flag);                                             //flag의 값을 chatClientForm으로 보냄
}


void ChatServerForm::on_clearPushButton_clicked()       //clear버튼 눌릴시 지움
{
    ui->messageTreeWidget->clear();
}

