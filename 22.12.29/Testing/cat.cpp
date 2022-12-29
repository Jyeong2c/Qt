#include "cat.h"
#include <QDebug>

Cat::Cat(QWidget *parent)
    : QWidget(parent)
{
}

Cat::~Cat()
{
}

void Cat::test()
{
    qInfo()<<"test";
}
void Cat::meow()
{
    qInfo()<<"meow";
}
void Cat::sleep()
{
    qInfo() <<"sleep";
}
void Cat::speak(QString value)
{
    qInfo() <<"sleep";
}
