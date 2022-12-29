#ifndef DOG_H
#define DOG_H

#include <QWidget>
#include <QObject>
#include <QDebug>

class Dog : public QObject
{
    Q_OBJECT

public:
    Dog(QObject *parent = nullptr);
    ~Dog();
private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();
    void bark();
    void rollover();
    void simple();
};
#endif // DOG_H
