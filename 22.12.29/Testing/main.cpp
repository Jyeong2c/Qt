#include "cat.h"

#include <QApplication>
#include <QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cat w;
    QTest::qExec(&w);
    w.show();
    return a.exec();
}
