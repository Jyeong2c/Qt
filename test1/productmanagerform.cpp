#include "productmanagerform.h"
#include "ui_productmanagerform.h"
#include "product.h"

#include <QFile>
#include <QMenu>

ProductManagerForm::ProductManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductManagerForm)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 540 << 400;
    ui->splitter->setSizes(sizes);          //스프리터 크기 설정

    QAction* removeAction = new QAction(tr("&Remove"));                 //삭제 액션 생성
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));     //triggered시 삭제

    menu = new QMenu;                   //메뉴 생성
    menu->addAction(removeAction);      //삭제 메뉴 추가
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);        //treeWidget 메뉴정책설정
    //시그널이 발생하면 showContextMenu 호출
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    //엔터키를 눌리면 searchPushButton 이 호출
    connect(ui->searchLineEdit, SIGNAL(returnPressed()), this, SLOT(on_searchPushButton_clicked()));
}

void ProductManagerForm::loadData()         //파일 생성(불러오기)
{
    QFile file("productList.txt");          //파일 이름 productList 설정(txt 파일)
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))      //파일 열때 조건문
        return;

    QTextStream in(&file);                          //파일을 불러오기
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");      //스트링으로 , 로 나눔
        if(row.size()) {
            int id = row[0].toInt();                //id값이 int 이므로 QString  변환
            Product* p = new Product(id, row[1], row[2], row[3],row[4]);
            ui->treeWidget->addTopLevelItem(p);
            productList.insert(id, p);              //productList에 값 넣기

            emit productAdd(id,row[1]);
        }
    }
    file.close( );
}

ProductManagerForm::~ProductManagerForm()       //소멸자
{
    delete ui;                                  //ui닫기
    QFile file("productList.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);                     //파일을 저장하기
    for (const auto& v : productList) {
        Product* p = v;
        out << p->id() << ", "
            << p->getProductName() << ", ";
        out << p->getPrice() << ", ";
        out << p->getQuantity() << ", ";
        out << p->getCountry() << "\n";
    }
    file.close( );
}



int ProductManagerForm::makeId( )               //id 값 설정
{
    if(productList.size( ) == 0) {              // 값이 없으면 product id는 5000부터 시작하게 return 값을 설정
        return 5000;
    } else {
        auto id = productList.lastKey();        //이전 값에 ++id 된 값으로 증가
        return ++id;
    }
}

void ProductManagerForm::showContextMenu(const QPoint &pos)     //마우스 위치 설정
{

    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}

void ProductManagerForm::on_addPushButton_clicked()             //추가 버튼 눌렸을 때
{

    QString productName,price, quantity,country;
    int id = makeId( );                                         //설정한 id값을 id에 대입
    price = ui ->priceLineEdit->text();                         //입력한 값을 price에 대입
    quantity = ui ->quantityLineEdit -> text();                 //입력한 값을 quantity에 대입
    productName = ui->productNameLineEdit->text();              //입력한 값을 productName에 대입
    country = ui->countryLineEdit->text();                      //입력한 값을 country에 대입
    if(productName .length()) {
        Product* p = new Product(id, productName,price,quantity,country);       //입력된 정보들을 productList에 추가
        productList.insert(id, p);
        ui->treeWidget->addTopLevelItem(p);
        emit productAdd(id,productName);
    }
    clearText();        //다음 입력값을 받기 위해 text에 입력했던 값을 지움
}

void ProductManagerForm::on_modifyPushButton_clicked()              //변경 버튼을 눌렸을 때
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();          //현재 treeWidget에 현재 정보를 item에 대입
    int index = ui->treeWidget->currentIndex().row();               //현재 정보들을 행으로 index에 대입
    if(item != nullptr) {                                           //아무것도 없을 때를 대비하여 예외 처리
        int key = item->text(0).toInt();                            //id값이 QString 형태이므로 변환 필요
        Product* p = productList[key];                              //prodcutList에 있는 정보를 id 값으로 찾는다
        QString productName,price, quantity,  country;
        productName = ui->productNameLineEdit->text();
        price = ui ->priceLineEdit->text();
        quantity = ui ->quantityLineEdit -> text();
        country = ui->countryLineEdit->text();

        p->setProductName(productName);                             //prodcutList에 있는 productName 값을 변경
        p->setPrice(price);                                         //prodcutList에 있는 price 값을 변경
        p->setQuantity(quantity);                                   //prodcutList에 있는 quantity 값을 변경
        p ->setCountry(country);                                    //prodcutList에 있는 country 값을 변경
        productList[key] = p;
        emit productModify(key,index,productName);
    }
    clearText();            //다음 입력값을 받기 위해 text에 입력했던 값을 지움
}

void ProductManagerForm::removeItem()       //정보 삭제
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();

    if(item != nullptr) {
        int i = ui->treeWidget->currentIndex().row();
        productList.remove(item->text(0).toInt());              //해당 id를 삭제
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
        ui->treeWidget->update();            //treeWidget을 업데이트

        emit productRemove(i);
    }
    clearText();        //다음 입력값을 받기 위해 text에 입력했던 값을 지움
}


void ProductManagerForm::on_searchPushButton_clicked()             //comboBox를 이용하여 항목별로 text를 입력받아 입력 받은 데이터를 찾아보여준다.
{
    ui->searchTreeWidget->clear();                                 //treeWidget을 정리
    int i = ui->searchComboBox->currentIndex();                    //찾을 항목을 comboBox로 보여줌
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains      //일치하는 정보를 찾는다
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);

        foreach(auto i, items) {
            Product* p = static_cast<Product*>(i);                  //찾은 정보를 searchTreeWidget에 추가해줍니다
            int id = p->id();
            QString productName = p->getProductName();
            QString price = p->getPrice();
            QString quantity = p->getQuantity();
            QString country= p->getCountry();
            Product* item = new Product(id,productName, price,quantity, country);
            ui->searchTreeWidget->addTopLevelItem(item);
        }
    }
}

void ProductManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{                                                           //treewidget에 정보을 선택했을때 textEdit에 정보 표시
    Q_UNUSED(column);                                       //column 사용하지 않는다는것을 알려준다. 적지 않아도 되지만 오류 메세지가 뜬다
    ui->idLineEdit->setText(item->text(0));                 //선택한 정보를 lineEdit에 보여줍니다
    ui->productNameLineEdit->setText(item->text(1));        //선택한 정보를 lineEdit에 보여줍니다
    ui->priceLineEdit->setText(item->text(2));              //선택한 정보를 lineEdit에 보여줍니다
    ui->quantityLineEdit->setText(item->text(3));           //선택한 정보를 lineEdit에 보여줍니다
    ui->countryLineEdit->setText(item->text(4));            //선택한 정보를 lineEdit에 보여줍니다
}

void ProductManagerForm::productData(int key)               //product정보를 shopmanager에 해당하는 정보를 보내 줌
{
    Product* p =productList[key];                           //map 사용으로 key로 해당 정보들을 찾음
    emit productInfo(p->getProductName(),p->getPrice()      //product의 정보를 shopmanager에 시그널로 넘김
                     ,p->getQuantity(),p->getCountry());
}
void ProductManagerForm::clearText()
//다음입력값을 받기 위해 textLineEdit를 지우는 함수
{
    ui->idLineEdit->clear();
    ui->productNameLineEdit->clear();
    ui->quantityLineEdit->clear();
    ui->priceLineEdit->clear();
    ui->countryLineEdit->clear();
}
