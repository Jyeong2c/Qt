#ifndef CHATCLIENTFORM_H
#define CHATCLIENTFORM_H

#include <QWidget>
#include <QDataStream>

class QTextEdit;
class QLineEdit;
class QTcpSocket;
class QPushButton;
class QFile;
class QProgressDialog;



typedef enum {
    Chat_Login,             // 로그인(서버 접속)   --> 초대를 위한 정보 저장
    Chat_In,                // 채팅방 입장
    Chat_Talk,              // 채팅
    Chat_Out,               // 채팅방 퇴장         --> 초대 가능
    Chat_LogOut,            // 로그 아웃(서버 단절) --> 초대 불가능
    Chat_Invite,            // 초대
    Chat_KickOut,           // 강퇴
} Chat_Status;


class ChatClientForm : public QWidget
{
    Q_OBJECT

public:
    const int PORT_NUMBER = 8000;
    ChatClientForm(QWidget *parent = nullptr);
    ~ChatClientForm();

private slots:
    void receiveData( );			// 서버에서 데이터가 올 때
    void sendData( );               // 서버로 데이터를 보낼 때
    void disconnect( );             // 연결 비활성화
    void sendProtocol(Chat_Status, char*, int = 1020);      //프로토콜보냄
    void sendFile();                //파일 보냄
    void goOnSend(qint64);
    void flagSended(int flag);      //없는 고객 이름 관련 예외 처리하기위해

private:
    void closeEvent(QCloseEvent*) override;

    QLineEdit *name;                // ID(이름)을 입력하는 창
    QTextEdit *message;             // 서버에서 오는 메세지 표시용
    QLineEdit* serverAddress;
    QLineEdit* serverPort;
    QLineEdit *inputLine;           // 서버로 보내는 메시지 입력용
    QPushButton *connectButton;     // 서버 로그인 등 접속 처리
    QPushButton *sentButton;        // 메시지 전송
    QPushButton* fileButton;        // 파일 전송
    QTcpSocket *clientSocket;		// 클라이언트용 소켓
    QTcpSocket *fileClient;
    QProgressDialog* progressDialog;    // 파일 진행 확인
    QFile* file;                    // 서버로 보내는 파일
    qint64 loadSize;                // 파일의 크기
    qint64 byteToWrite;             // 보내는 파일의 크기
    qint64 totalSize;               // 전체 파일의 크기
    QByteArray outBlock;            // 전송을 위한 데이터
    bool isSent;
    int flag;                       //
    int chatFlag =0;                   //강퇴시 메시지 뜬느것을 방지
signals:
    void sendClientName(QString);
};
#endif // CHATCLIENTFORM_H









