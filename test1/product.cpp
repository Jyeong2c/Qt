#include "product.h"

#include <QLabel>
#include <iostream>

using namespace std;

Product::Product(int id, QString productName,QString price, QString quantity,  QString country )
{
    setText(0, QString::number(id));        // 제품 id
    setText(1, productName);                // 제품명
    setText(2, price);                      // 제품 가격
    setText(3, quantity);                   // 제품 개수
    setText(4, country);                    // 제조국 (제조회사)

}


QString Product::getProductName() const                 //제품명을 QString으로 설정
{
    return text(1);
}

void Product::setProductName(QString& productName)
{
    setText(1, productName);
}
QString Product::getPrice() const                       //제품가격을 QString으로 설정 이후 계산 할때는 toInt를 사용
{
    return text(2);
}

void Product::setPrice(QString& price)

{
    setText(2, price);
}

QString Product::getQuantity() const                    //제품개수를 QString으로 설정
{
    return text(3);
}

void Product::setQuantity(QString& quantity)
{
    setText(3, quantity);
}

QString Product::getCountry() const                     //제조국을 QString으로 설정
{
    return text(4);
}

void Product::setCountry(QString& country)
{
    setText(4, country);
}

int Product::id() const                                 //할당 받는 아이디를 int로 설정
{
    return text(0).toInt();
}

// Define copy assignment operator.                     값을 비교하기 위해서 설정 (text(1)으로 설정하였기 때문에 제품명으로 비교)
//bool Product::operator==(const Product &other) const {
//    return (this->text(1) == other.text(1));
//}

