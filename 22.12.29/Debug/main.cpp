#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>


void myDebugMsg(QtMsgType type,const QMessageLogContext & context, const QString &msg)
{
    switch(type){
    case QtDebugMsg:
        fprintf(stderr,"Debug: %s\n",qPrintable(msg));
        break;
    case QtWarningMsg:
        fprintf(stderr,"Warning: %s\n",qPrintable(msg));
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fata;: %s\n",qPrintable(msg));
        abort();
    }
}
int main(int argc, char *argv[])
{
    qInstallMessageHandler(myDebugMsg);
    qDebug("qDebug");
    qInfo("qInfo");
    qWarning("qWarning");
    qCritical("qCritical");
//    qFatal("qFatal");

    QCoreApplication a(argc, argv);

    return a.exec();
}
