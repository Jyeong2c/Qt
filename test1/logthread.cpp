#include "logthread.h"

#include <QTreeWidgetItem>
#include <QFile>
#include <QDateTime>

LogThread::LogThread(QObject *parent)
    : QThread{parent}
{
    QString format = "yyyyMMdd_hhmmss";                    //파일이름으로 지정하기 위한 형식
    filename = QString("log_%1.txt").arg(QDateTime::currentDateTime().toString(format));
}

void LogThread::run()                                       //실행
{
    Q_FOREVER {
        saveData();
        sleep(60);                                          // 1분마다 저장
    }
}

void LogThread::appendData(QTreeWidgetItem* item)           //itemList에 추가
{
    itemList.append(item);
}

void LogThread::saveData()                                  //데이터 저장
{
    if(itemList.count() > 0) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //파일을 열 때 조건문
            return;

        QTextStream out(&file);
        foreach(auto item, itemList) {      //파일을 돌면서 저장
            out << item->text(0) << ", ";
            out << item->text(1) << ", ";
            out << item->text(2) << ", ";
            out << item->text(3) << ", ";
            out << item->text(4) << ", ";
            out << item->text(5) << "\n";
        }
        file.close();
    }
}
