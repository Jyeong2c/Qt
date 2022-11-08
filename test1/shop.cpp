#include "shop.h"

#include <QLabel>
#include <iostream>
#include <QDateTimeEdit>

Shop::Shop(int id, QString name , QString productName , QString  price, QString date , QString amount , QString discount ,QString totalPrice)
{
    setText(0, QString::number(id));                //주문 ID
    setText(1, name);                               //고객 이름
    setText(2, productName);                        //제품명
    setText(3, price);                              //제품 가격
    setText(4, date);                               //주문날짜
    setText(5, amount);                             //주문량
    setText(6, discount);                           //할인율
    setText(7, totalPrice);                         //총 가격
}

QString Shop::getName() const                       //고객이름 QString 으로 설정
{
    return text(1);
}
void Shop::setName(QString&name)
{
    setText(1, name);
}
QString Shop::getProductName() const                //제품명 QString 으로 설정
{
    return text(2);
}
void Shop::setProductName(QString&productName)
{
    setText(2, productName);
}
QString Shop::getPrice() const                      //제품가격 QString 으로 설정
{
    return text(3);
}
void Shop::setPrice(QString&price)
{
    setText(3, price);
}
QString Shop::getDate() const                       //주문 날짜 QString 으로 설정
{
    return text(4);
}
void Shop::setDate(QString&date)
{
    setText(4, date);
}
QString Shop::getAmount() const                     //주문량을 QString 으로 설정
{
    return text(5);
}
void Shop::setAmount(QString&amount)
{
    setText(5, amount);
}
QString Shop::getDiscount() const                   //할인율 QString 으로 설정
{
    return text(6);
}
void Shop::setDiscount(QString&discount)
{
    setText(6, discount);
}
QString Shop::getTotalPrice()const                  //총 금액을 QString 으로 설정
{
    return text(7);
}
void Shop::setTotalPrice(QString&totalprice)
{
    setText(7, totalprice);
}
int Shop::id()const                               //주문 id를 int로 설정
{
    return text(0).toInt();
}
// 다른 클래스에서 키값을 찾기 위해서 비교연산자를 이용하여
//값을 비교 하기 위해서 설정 (현재 사용x)
bool Shop::operator==(const Shop &other) const
{
    return (this->text(0) == other.text(0));
}
