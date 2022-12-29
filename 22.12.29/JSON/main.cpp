#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

void sendRequest();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    sendRequest();
    return a.exec();
}
void sendRequest()
{
    //스택위의 임시 이벤트 루프
    QEventLoop eventLoop;

    //"finished()"가 불려지면 이벤트 루프를 종료 ("quit()")
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));

    //HTTP요청
    QNetworkRequest req(QUrl(QString("http://time.jsontest.com/")));
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();  //"finished()"가 호출될 때까지 블록

    if(reply->error() ==QNetworkReply::NoError){
        QString strReply = (QString)reply->readAll();

        //Json 파싱
        qDebug()<<"Response:"<<strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject jsonObj = jsonResponse.object();
        qDebug()<<"Time:"<<jsonObj["time"].toString();
        qDebug()<<"Date:"<<jsonObj["date"].toString();
        delete reply;
    }else{  //오류시
        qDebug()<<"Failure:"<<reply->errorString();
        delete reply;
    }
}
