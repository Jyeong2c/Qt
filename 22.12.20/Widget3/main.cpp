#include "widget3.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget3 w;
    w.show();
    return a.exec();
}
