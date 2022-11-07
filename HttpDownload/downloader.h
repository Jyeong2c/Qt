#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject * parent =0);
signals:
public slots:
   void replyFinished(QNetworkReply* reply);
private:
QNetworkAccessManager *manager;
};

#endif // DOWNLOADER_H
