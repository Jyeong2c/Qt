#ifndef CAT_H
#define CAT_H

#include <QWidget>

class Cat : public QWidget
{
    Q_OBJECT

public:
    Cat(QWidget *parent = nullptr);
    ~Cat();
    void test();
private slots:
    void meow();
    void sleep();
    void speak(QString value);
};
#endif // CAT_H
