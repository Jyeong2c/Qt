#ifndef PRODUCT_H
#define PRODUCT_H

#include <QTreeWidgetItem>


class Product : public QTreeWidgetItem
{
public:
    explicit Product(int id = 0,QString ="", QString="", QString = "", QString = "");

    QString getProductName() const;         //제품명
    void setProductName(QString&);
    QString getPrice()const;                //제품가격
    void setPrice(QString&);
    QString getQuantity()const;             //제품개수
    void setQuantity(QString&);
    QString getCountry() const;             //제조국(제조회사)
    void setCountry(QString&);

    int id() const;                         //제품 id

    //bool operator==(const Product &other) const;
};

#endif // PRODUCT_H



