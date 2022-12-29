#ifndef SAVEURLS_H
#define SAVEURLS_H

//class QStringList
#include <QStringList>

class Saveurls
{
public:
    Saveurls();

    void save(QStringList);
    QStringList load();
};

#endif // SAVEURLS_H
