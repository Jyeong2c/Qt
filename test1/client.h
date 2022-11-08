#ifndef CLIENTITEM_H
#define CLIENTITEM_H

#include <QTreeWidgetItem>

class Client : public QTreeWidgetItem
{
public:
    explicit Client(int id = 0, QString = "", QString = "", QString = "");

    QString getName() const;            //고객이름
    void setName(QString&);
    QString getPhoneNumber() const;     //고객 휴대폰 번호
    void setPhoneNumber(QString&);
    QString getAddress() const;         //고객주소
    void setAddress(QString&);
    int id() const;                     //고객 id
    //bool operator==(const Client &other) const;
};

#endif // CLIENTITEM_H
