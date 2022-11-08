#ifndef SHOP_H
#define SHOP_H

#include <QTreeWidgetItem>

class Shop : public QTreeWidgetItem
{
public:
    explicit Shop(int=3000, QString = "", QString = "", QString = "", QString = "" , QString = "" ,QString = "",QString = ""   );

    QString getName()const;             //고객이름
    void setName(QString &);
    QString getProductName()const;      //제품명
    void setProductName(QString &);
    QString getPrice()const;            //제품가격
    void setPrice(QString &);
    QString getDate() const;            //주문날짜
    void setDate(QString&);
    QString getAmount() const;          //주문 수량
    void setAmount(QString&);
    QString getDiscount() const;        //할인율
    void setDiscount(QString&);
    QString getTotalPrice()const;		//총금액
    void setTotalPrice(QString&);

    int id()const;                      //주문 id

    bool operator==(const Shop &other) const;


};

#endif // SHOP_H
