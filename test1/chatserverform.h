#ifndef CHATSERVERFORM_H
#define CHATSERVERFORM_H

#include "chatclientform.h"
#include <QWidget>
#include <QList>
#include <QHash>

class QLabel;
class QTcpServer;
class QTcpSocket;
class QFile;
class QProgressDialog;
class LogThread;

namespace Ui {
class ChatServerForm;
}

namespace Ui {
class ChatServerForm;
}

class ChatServerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChatServerForm(QWidget *parent = nullptr);
    ~ChatServerForm();

private:
    const int BLOCK_SIZE = 1024;            //블락사이즈
    const int PORT_NUMBER = 8000;           //포트 번호선언

    Ui::ChatServerForm *ui;                 //Ui 생성
    QTcpServer *chatServer;                 //TcpServer
    QTcpServer *fileServer;                 //fileServer
    QHash<quint16, QString> clientNameHash; //고객이름으로 찾음
    QHash<QString, QTcpSocket*> clientSocketHash;       //이름으로 소켓을 찾는다, hash를 이용하면 빠르기때문
    QHash<QString, int> clientIDHash;       //고객 id로 찾음
    QMenu* menu;                            //메뉴
    QFile* file;                            //파일
    QProgressDialog* progressDialog;        //프로그레스바 (파일 전송시)
    qint64 totalSize;                       //토탈 사이즈
    qint64 byteReceived;                    //바이트 받음
    QByteArray inBlock;
    LogThread* logThread;                   //로그스레드

private slots:
    void acceptConnection();                /* 파일 서버 */
    void readClient();

    void clientConnect( );                  /* 채팅 서버 */
    void receiveData( );                    //data 받음
    void removeClient( );                   //제거
    void addClient(int, QString);           //고객 정보 추가
    void removeClientList(int i);           //고객 식제시 리스트에서 삭제
    void modifyClientList(int ,int , QString );     //고객 변경시 리스트 변경
    void inviteClient();                    //초대
    void kickOut();                         //강퇴
    void on_clientTreeWidget_customContextMenuRequested(const QPoint &pos);
    void clientNameSended(QString);         //고객이름 받음
    void on_clearPushButton_clicked();      //messageWidget을 지우기 위해

signals:
    void sendFlag(int);                     //고객리스트에 없는 고객이 있는지를 확인하기 위해

};

#endif // CHATSERVERFORM_H
