#include "client.h"

#include <QLabel>
#include <iostream>

using namespace std;

Client::Client(int id, QString name, QString phoneNumber, QString address)
{                                           //고객 정보 설정
    setText(0, QString::number(id));        //clientId  설정
    setText(1, name);                       //clientName 설정
    setText(2, phoneNumber);                //clientPhoneNumber 설정
    setText(3, address);                    //clientAddress 설정
}

QString Client::getName() const                         //이름이라 QString으로 설정
{
    return text(1);
}

void Client::setName(QString& name)
{
    setText(1, name);
}

QString Client::getPhoneNumber() const                  //휴대폰 번호 QString으로 설정
{
    return text(2);
}

void Client::setPhoneNumber(QString& phoneNumber)
{
    setText(2, phoneNumber);
}

QString Client::getAddress() const                      //주소는 QString으로 설정
{
    return text(3);
}

void Client::setAddress(QString& address)
{
    setText(3, address);
}

int Client::id() const                                  //id 값은 숫자이므로 int로 설정
{
    return text(0).toInt();
}

// Define copy assignment operator.
//bool Client::operator==(const Client &other) const {
//    return (this->text(1) == other.text(1));            //값을 비교하기 위해서 설정(text(1)으로 설정하였기 때문에 이름으로 비교함
//}
