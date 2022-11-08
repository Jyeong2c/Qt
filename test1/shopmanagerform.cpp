#include "shopmanagerform.h"
#include "ui_shopmanagerform.h"
#include "shop.h"
#include <QFile>
#include <QMenu>
#include <QDateTime>


ShopManagerForm::ShopManagerForm( QWidget *parent) : QWidget(parent),

    ui(new Ui::ShopManagerForm)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 540 << 400;
    ui->splitter->setSizes(sizes);          //스프리터 크기 설정

    QAction* removeAction = new QAction(tr("&Remove"));               //삭제 액션 생성
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));   //triggered시 삭제

    menu = new QMenu;                           //메뉴 생성
    menu->addAction(removeAction);              //삭제 메뉴 추가
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);     //treeWidget 메뉴정책설정

    //시그널이 발생하면 showContextMenu 호출
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)),
                                this, SLOT(showContextMenu(QPoint)));
    //엔터키를 눌리면 searchPushButton 이 호출
    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
                            this, SLOT(on_searchPushButton_clicked()));

//    ui->treeWidget->header()->resizeSection(0, 50);
//    ui->treeWidget->header()->resizeSections(QHeaderView::ResizeToContents);        //treeWidget 항목 사이즈
//    ui->clientTreeWidget->header()->resizeSections(QHeaderView::ResizeToContents);
//    ui->productTreeWidget->header()->resizeSections(QHeaderView::ResizeToContents);

}
void ShopManagerForm::loadData()            //파일 저장
{
    QFile file("shopList.txt");             //파일 이름 clientlist 설정(txt 파일)
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))   //파일 열때 오류 검사
        return;                                              //오류가 발생 하면 return

    QTextStream in(&file);                                   //파일을 불러오기
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");              //스트링으로 , 로 나눔
        if(row.size()) {
            int id = row[0].toInt();                 //id값이 int 이므로 QString  변환
            Shop* s = new Shop(id, row[1], row[2], row[3],
                            row[4], row[5], row[6], row[7]);
            ui->treeWidget->addTopLevelItem(s);
            shopList.insert(id, s);                       //clientList에 값 넣기
        }
    }

    file.close( );

}

//id를 키값으로 clientList에 있는 name을 comboBox에 추가
void ShopManagerForm::clientName(int id, QString name)
{
    clientIDList <<id;
    ui->clientIdcomboBox->addItem(name);

}
//client에서 고객의 정보를 변경하면 comboBox에서도 정보를 바뀌게 하기 위해
void ShopManagerForm::clientNameModify(int key,int index, QString name)
{
    ui->clientIdcomboBox->setItemText(index, name);
}
void ShopManagerForm::clientNameRemove(int index)     //client에서 고객을 제거 할 때 comboBox에서도 삭제하기 위해
{
    ui->clientIdcomboBox->blockSignals(true);
    ui->clientIdcomboBox->removeItem(index);    //comboBox에 있는 해당 index 정보를 삭제
    ui->clientIdcomboBox->blockSignals(false);  //client 0 번째 index를 지우면 currentIndexChanged 값이 -1이 되는것을 막기위해
}
//comboBox가 바뀔 때  clientAddUpdate신호가 발생
void ShopManagerForm::on_clientIdcomboBox_currentIndexChanged(int index)
{
    emit clientAddUpdate(clientIDList[index]);
}
//comboBox가 바뀔 때 clientTreeWidget에 바뀐 이름의 정보들을 보여준다
void ShopManagerForm::clientAddUpdate(QString name,QString phoneNumber,QString address)
{
    ui->clientTreeWidget ->clear();
    QTreeWidgetItem *item =new QTreeWidgetItem(ui->clientTreeWidget);
    item->setText(0, name);
    item->setText(1, phoneNumber);
    item->setText(2, address);
}

void ShopManagerForm::productName(int id, QString productName)
{
    productIDList<<id;
    ui->productNamecomboBox->addItem(productName);
}
//product에서 고객을 제거 할 때 comboBox에서도 삭제하기 위해
void ShopManagerForm::productNameRemove(int index)
{
    ui->productNamecomboBox->blockSignals(true);
    ui->productNamecomboBox->removeItem(index);       //comboBox에 있는 해당 index 정보를 삭제
    ui->productNamecomboBox->blockSignals(false);     //client 0 번째 index를 지우면 currentIndexChanged 값이 -1이 되는것을 막기위해
}

//client에서 고객의 정보를 변경하면 comboBox에서도 정보를 바뀌게 하기 위해
void ShopManagerForm::productNameModify(int key,int index , QString productName)
{
    ui->productNamecomboBox->setItemText(index,productName);
}
//comboBox가 바뀔 때  clientAddUpdate신호가 발생
void ShopManagerForm::on_productNamecomboBox_currentIndexChanged(int index)
{

    emit productAddUpdate(productIDList[index]);
}

//comboBox가 바뀔 때 clientTreeWidget에 바뀐 이름의 정보들을 보여준다
void ShopManagerForm::productAddUpdate (QString productName,QString price, QString quantity,QString country)
{
    ui->productTreeWidget -> clear();
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->productTreeWidget);
    item->setText(0, productName);
    item->setText(1,price);
    item->setText(2, quantity);
    item->setText(3,country);

    ui->priceLineEdit->setText(price);          //해당하는 가격 보여 줌   //totalprice를 계산 함
    ui->totalPriceLineEdit->setText(QString::number((price.toInt()* ui->amountLineEdit->text().toInt())
                                                    -(ui->amountLineEdit->text().toInt()* ui->discountLineEdit->text().toInt() /100)));
}

int ShopManagerForm::makeId( )          //id 값 설정
{
    if(shopList.size( ) == 0) {         // 값이 없으면 shop id는 10000부터 시작하게 return 값을 설정
        return 10000;
    } else {
        auto id = shopList.lastKey();
        return ++id;                    //이전 값에 ++id 된 값으로 증가
    }
}

//마우스 위치를 알려준다( remove)
void ShopManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}

//추가 버튼 눌렸을 때
void ShopManagerForm::on_addPushButton_clicked()
{

    QString name,productName, price,date,amount, discount,totalPrice;
    int id = makeId( );

    //QDateEdit * dateEdit =new QDateEdit(QDate::currentDate(),0);

    name = ui->clientIdcomboBox->currentText();             //현재 나와 있는 값들을 대입
    productName =ui->productNamecomboBox->currentText();
    price =ui->priceLineEdit->text();
    date.append(QDateTime::currentDateTime().toString());   //현재 날짜 및 시간을 date에 추가 해준다
    amount = ui->amountLineEdit->text();
    discount = ui->discountLineEdit->text();
    totalPrice = ui->totalPriceLineEdit->text();            //readOnly로 계산한 값을 대입
    if(date .length()) {
        Shop* s = new Shop(id, name,productName, price,date,amount,discount,totalPrice);
        shopList.insert(id, s);                     //입력된 정보들을 clientList에 추가
        ui->treeWidget->addTopLevelItem(s);

    }
}

//변경 버튼을 눌렸을 때
void ShopManagerForm::on_modifyPushButton_clicked()
{

    QTreeWidgetItem* item = ui->treeWidget->currentItem();     //현재 treeWidget에 현재 정보를 item에 대입
    if(item != nullptr) {                                      //아무것도 없을 때를 대비하여 예외 처리
        int key = item->text(0).toInt();                       //id값이 QString 형태이므로 변환 필요
        Shop* s = shopList[key];                               //shopList에 있는 정보를 id 값으로 찾는다
        QString name , productName, price,date,amount, discount,totalPrice;


        name = ui->clientIdcomboBox->currentText();
        productName = ui->productNamecomboBox->currentText();
        price = ui->priceLineEdit->text();
        amount = ui ->amountLineEdit->text();
        discount = ui ->discountLineEdit -> text();
        totalPrice = ui->totalPriceLineEdit->text();

        s->setName(name);                               //shopList에 있는 name 값을 변경
        s->setProductName(productName);                 //shopList에 있는 productName 값을 변경
        s->setPrice(price);                             //shopList에 있는 price 값을 변경
        s->setAmount(amount);                           //shopList에 있는 amount 값을 변경
        s->setDiscount(discount);                       //shopList에 있는 discount 값을 변경
        s ->setTotalPrice(totalPrice);                  //shopList에 있는 totalPrice 값을 변경
        shopList[key] = s;

    }
}

void ShopManagerForm::removeItem()                      //정보 삭제
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if(item != nullptr) {
        shopList.remove(item->text(0).toInt());         //해당 id를 삭제
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
        ui->treeWidget->update();                       //treeWidget을 업데이트
    }
}

void ShopManagerForm::on_searchPushButton_clicked()      //찾기 버튼 눌렸을 때
{
    ui->searchTreeWidget->clear();                      //treeWidget을 정리
    int i = ui->searchComboBox->currentIndex();         //찾을 항목을 comboBox로 보여줌
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);  //일치하는 정보를 찾는다

        foreach(auto i, items) {
            Shop* s = static_cast<Shop*>(i);            //찾은 정보를 searchTreeWidget에 추가해줍니다
            int id = s->id();

            QString name = s->getName();
            QString productName = s->getProductName();
            QString price = s->getPrice();
            QString date = s->getDate();
            QString amount = s->getAmount();
            QString discount = s->getDiscount();
            QString totalPrice= s->getTotalPrice();
            Shop* item = new Shop(id,name,productName,price,date, amount,discount, totalPrice);
            ui->searchTreeWidget->addTopLevelItem(item);
        }
    }
}

//등록된 정보를 눌렸을 때
void ShopManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);          //column 사용하지 않는다는것을 알려준다. 적지 않아도 되지만 오류 메세지가 뜬다
    ui->idLineEdit->setText(item->text(0));                  //선택한 정보를 lineEdit에 보여줍니다
    ui->clientIdcomboBox->setCurrentText(item->text(1));     //선택한 정보를 lineEdit에 보여줍니다
    ui->productNamecomboBox->setCurrentText(item->text(2));  //선택한 정보를 lineEdit에 보여줍니다
    ui->priceLineEdit->setText(item->text(3));               //선택한 정보를 lineEdit에 보여줍니다
    ui->amountLineEdit->setText(item->text(5));              //선택한 정보를 lineEdit에 보여줍니다
    ui->discountLineEdit->setText(item->text(6));            //선택한 정보를 lineEdit에 보여줍니다
    ui->totalPriceLineEdit->setText(item->text(7));          //선택한 정보를 lineEdit에 보여줍니다
}

ShopManagerForm::~ShopManagerForm()                          //소멸자
{
    QFile file("shopList.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);                                 //파일을 저장하기
    for(int i=0; i<ui->treeWidget->topLevelItemCount(); i++){
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);
        for(int j =0; j < 7; j++){
            out<<item->text(j)<<", ";
        }
        out<<item->text(7)<< "\r\n";
    }
    file.close( );                                          //파일 닫는다
    delete ui;                                              //ui 닫는다
}
//주문 수량 값이 변경 될 때
void ShopManagerForm::on_amountLineEdit_textChanged(const QString &arg1)
{
    //할인율이 들어가지 않은 값을 계산
    ui->totalPriceLineEdit->setText(QString::number(ui->priceLineEdit->text().toInt()
                                                    *arg1.toInt()));
}

//할인율 값을 쓸 때 총 금액의 값을 계산
void ShopManagerForm::on_discountLineEdit_textChanged(const QString &arg1)
{
    ui->totalPriceLineEdit->setText(QString::number((ui->priceLineEdit->text().toInt()
                                                     * ui->amountLineEdit->text().toInt())
                                                    -(ui->priceLineEdit->text().toInt()
                                                      *ui->amountLineEdit->text().toInt()
                                                      * arg1.toInt() /100)));
}
