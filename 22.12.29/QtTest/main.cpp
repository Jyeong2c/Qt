#include "dog.h"
#include <QDebug>
#include <QTest>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dog w;
    QTest::qExec(&w);
//    w.show();
    return a.exec();
}
