#include "domreader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DomReader w;
    w.show();
    return a.exec();
}
