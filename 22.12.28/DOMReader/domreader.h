#ifndef DOMREADER_H
#define DOMREADER_H

#include <QWidget>

class DomReader : public QWidget
{
    Q_OBJECT

public:
    DomReader(QWidget *parent = nullptr);
    ~DomReader();
};
#endif // DOMREADER_H
