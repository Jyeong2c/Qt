#include "mainwindow.h"
//#include "chatclientform.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
//    QWidget z;
//    z.show();
    w.show();
    return a.exec();
}
