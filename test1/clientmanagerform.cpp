//#include "clientmanagerform.h"
//#include "ui_clientmanagerform.h"
//#include "client.h"

//#include <QFile>
//#include <QMenu>

//ClientManagerForm::ClientManagerForm(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::ClientManagerForm)
//{
//    ui->setupUi(this);

//    QList<int> sizes;                       //크기 설정
//    sizes << 540 << 400;
//    ui->splitter->setSizes(sizes);          //스프리터 크기 설정

//    QAction* removeAction = new QAction(tr("&Remove"));                     //삭제 액션 생성
//    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));         //triggered시 삭제

//    menu = new QMenu;                       //메뉴 생성
//    menu->addAction(removeAction);          //삭제 메뉴 추가
//    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);            //treeWidget 메뉴정책설정
//    //시그널이 발생하면 showContextMenu 호출
//    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
//    //엔터키를 눌리면 searchPushButton 이 호출
//    connect(ui->searchLineEdit, SIGNAL(returnPressed()), this, SLOT(on_searchPushButton_clicked()));



//}
//void ClientManagerForm::loadData()      //파일 저장
//{
//    QFile file("clientlist.txt");       //파일 이름 clientlist 설정(txt 파일)
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))      //파일 열때 조건문
//        return;                                                 //오류가 발생 하면 return

//    QTextStream in(&file);                         //파일을 불러오기
//    while (!in.atEnd()) {
//        QString line = in.readLine();
//        QList<QString> row = line.split(", ");      //스트링으로 , 로 나눔
//        if(row.size()) {
//            int id = row[0].toInt();                //id값이 int 이므로 QString  변환
//            Client* c = new Client(id, row[1], row[2], row[3]);
//            ui->treeWidget->addTopLevelItem(c);
//            clientList.insert(id, c);               //clientList에 값 넣기

//            emit clientAdd(id,row[1]);

//        }

//    }
//    file.close( );
//}
//ClientManagerForm::~ClientManagerForm()         //소멸자
//{
//    delete ui;                                  //ui닫기

//    QFile file("clientlist.txt");
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//        return;

//    QTextStream out(&file);                     //파일을 저장하기
//    for (const auto& v : clientList) {
//        Client* c = v;
//        out << c->id() << ", " << c->getName() << ", ";
//        out << c->getPhoneNumber() << ", ";
//        out << c->getAddress() << "\n";
//    }
//    file.close( );
//}

//int ClientManagerForm::makeId( )        //id 값 설정
//{
//    if(clientList.size( ) == 0) {       // 값이 없으면 client id는 1부터 시작하게 return 값을 설정
//        return 1;
//    } else {
//        auto id = clientList.lastKey();    //이전 값에 ++id 된 값으로 증가
//        return ++id;
//    }
//}

//void ClientManagerForm::showContextMenu(const QPoint &pos)      //마우스 위치 설정
//{
//    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
//    menu->exec(globalPos);
//}


//void ClientManagerForm::on_addPushButton_clicked()              //추가 버튼 눌렸을 때
//{
//    QString name, number, address;
//    int id = makeId( );                                         //설정한 id값을 id에 대입
//    name = ui->nameLineEdit->text();                            //입력한 값을 name에 대입
//    number = ui->phoneNumberLineEdit->text();                   //입력한 값을 number에 대입
//    address = ui->addressLineEdit->text();                      //입력한 값을 address에 대입
//    if(name.length()) {
//        Client* c = new Client(id, name, number, address);      //입력된 정보들을 clientList에 추가
//        ui->treeWidget->addTopLevelItem(c);
//        clientList.insert(id, c);
//        emit clientAdd(id, name);
//    }
//    clearText();            //다음 입력값을 받기 위해 text에 입력했던 값을 지움

//}
//void ClientManagerForm::on_modifyPushButton_clicked()           //변경 버튼을 눌렸을 때
//{
//    QTreeWidgetItem* item = ui->treeWidget->currentItem();      //현재 treeWidget에 현재 정보를 item에 대입
//    int index = ui->treeWidget->currentIndex().row();           //현재 정보들을 행으로 index에 대입
//    if(item != nullptr) {                                       //아무것도 없을 때를 대비하여 예외 처리
//        int key = item->text(0).toInt();                        //id값이 QString 형태이므로 변환 필요
//        Client* c = clientList[key];                            //clientList에 있는 정보를 id 값으로 찾는다
//        QString name, number, address;
//        name = ui->nameLineEdit->text();
//        number = ui->phoneNumberLineEdit->text();
//        address = ui->addressLineEdit->text();
//        c->setName(name);                       //clientList에 있는 name 값을 변경
//        c->setPhoneNumber(number);              //clientList에 있는 phoneNumber 값을 변경
//        c->setAddress(address);                 //clientList에 있는 address 값을 변경
//        clientList[key] = c;
//        emit clientModify(key,index,name);
//    }
//    clearText();            //다음 입력값을 받기 위해 text에 입력했던 값을 지움
//}

//void ClientManagerForm::removeItem()                //정보 삭제
//{
//    QTreeWidgetItem* item = ui->treeWidget->currentItem();
//    int index = ui->treeWidget->currentIndex().row();
//    if(item != nullptr) {
//        clientList.remove(item->text(0).toInt());    //해당 id를 삭제
//        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
//        ui->treeWidget->update();                  //treeWidget을 업데이트
//        emit clientRemove(index);
//    }
//    clearText();            //다음 입력값을 받기 위해 text에 입력했던 값을 지움
//}


//void ClientManagerForm::on_searchPushButton_clicked()       //찾기 버튼 눌렸을 때
//{
//    ui->searchTreeWidget->clear();                          //treeWidget을 정리
//    //    for(int i = 0; i < ui->treeWidget->columnCount(); i++)
//    int i = ui->searchComboBox->currentIndex();             //찾을 항목을 comboBox로 보여줌
//    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
//                   : Qt::MatchCaseSensitive;
//    {
//        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);        //일치하는 정보를 찾는다

//        foreach(auto i, items) {
//            Client* c = static_cast<Client*>(i);            //찾은 정보를 searchTreeWidget에 추가해줍니다
//            int id = c->id();
//            QString name = c->getName();
//            QString number = c->getPhoneNumber();
//            QString address = c->getAddress();
//            Client* item = new Client(id, name, number, address);
//            ui->searchTreeWidget->addTopLevelItem(item);

//        }
//    }
//}


//void ClientManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)        //등록된 정보를 눌렸을 때
//{
//    Q_UNUSED(column);       //column 사용하지 않는다는것을 알려준다. 적지 않아도 되지만 오류 메세지가 뜬다
//    ui->idLineEdit->setText(item->text(0));             //선택한 정보를 lineEdit에 보여줍니다
//    ui->nameLineEdit->setText(item->text(1));           //선택한 정보를 lineEdit에 보여줍니다
//    ui->phoneNumberLineEdit->setText(item->text(2));    //선택한 정보를 lineEdit에 보여줍니다
//    ui->addressLineEdit->setText(item->text(3));        //선택한 정보를 lineEdit에 보여줍니다
//}


//void ClientManagerForm::clientData(int key)         //client정보를 shopmanager에 해당하는 정보를 보내 줌
//{
//    Client * c =clientList[key];                    //map 사용으로 key로 해당 정보들을 찾음
//    emit clientInfo(c->getName(),c->getPhoneNumber(),c->getAddress());
//}
//void ClientManagerForm::clearText()         //add,modify,remove버튼을 눌릴때 textLine을 지우기 위한 함수
//                                            //다음입력값을 받기 위해 textLineEdit를 지우는 함수
//{
//    ui->idLineEdit->clear();
//    ui->nameLineEdit->clear();
//    ui->phoneNumberLineEdit->clear();
//    ui->addressLineEdit->clear();
//}
#include "clientmanagerform.h"
#include "ui_clientmanagerform.h"
#include "client.h"

#include <QFile>
#include <QMenu>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlQueryModel>

ClientManagerForm::ClientManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientManagerForm)
{
    ui->setupUi(this);

    QList<int> sizes;                       //크기 설정
    //sizes << 540 << 400;
    //ui->splitter->setSizes(sizes);          //스프리터 크기 설정

    QAction* removeAction = new QAction(tr("&Remove"));                     //삭제 액션 생성
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));         //triggered시 삭제

    menu = new QMenu;                       //메뉴 생성
    menu->addAction(removeAction);          //삭제 메뉴 추가
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);            //treeWidget 메뉴정책설정
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    //시그널이 발생하면 showContextMenu 호출
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showContextMenu1(QPoint)));
    //엔터키를 눌리면 searchPushButton 이 호출
    connect(ui->searchLineEdit, SIGNAL(returnPressed()), this, SLOT(on_searchPushButton_clicked()));

}



//bool ClientManagerForm::dbAddclient()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("clientDB"/*"person"*/);
//    query.exec("CREATE TABLE IF NOT EXISTS clientDB(id INTEGER Primary Key,"      //primary 키가 존재하지 않으면
//               "name VARCHAR(20) NOT NULL, phoneNumber VARCHAR(20),address VARCHAR(20));");
//    if(!db.open())return false;
//    query.prepare("INSERT INTO clientDB (id,name,phoneNumber,address)"
//                  "VALUES (:id,:name,:phoneNumber,:address)");
//    query.bindValue(":id",makeId());
//    query.bindValue(":name",ui->nameLineEdit->text());
//    query.bindValue(":phoneNumber",ui->phoneNumberLineEdit->text());
//    query.bindValue(":address",ui->addressLineEdit->text());
//    query.exec();
//}

bool ClientManagerForm::createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("clientDB.db");         //db 파일로 저장       파일명뒤에 .db랑 그냥 파일명만 적을 때 같다.
    if(!db.open())return false;

    QSqlQuery *query = new QSqlQuery;
    query->exec("CREATE TABLE IF NOT EXISTS clientDB(id INTEGER Primary Key,"      //primary 키가 존재하지 않으면
                "name VARCHAR(20) NOT NULL, number VARCHAR(20),address VARCHAR(20));");
    return true;
}

//void ClientManagerForm::dbLoadData()
//{
//    QSqlQuery query("SELECT * FROM clientDB");
//    while (query.next()) {
//        QString id = query.value(0).toString();
//        doSomething(id);
//    QSqlTableModel queryModel;
//    queryModel.setTable("clientDB");
//    //queryModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
//    queryModel.select();

//    queryModel.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
//    queryModel.setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
//    queryModel.setHeaderData(2, Qt::Horizontal, QObject::tr("phoneNumber"));
//    queryModel.setHeaderData(3, Qt::Horizontal, QObject::tr("address"));

//    QTableView *tableview =new QTableView;
//    tableview->setModel(&queryModel);
//    tableview->setWindowTitle(QObject::tr("Query Model"));
////    tableview->hideColumn(0);
//    tableview->show();
//}
void ClientManagerForm::loadData()      //파일 저장
{
    QFile file("clientlist.txt");       //파일 이름 clientlist 설정(txt 파일)
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))      //파일 열때 조건문
        return;                                                 //오류가 발생 하면 return

    QTextStream in(&file);                         //파일을 불러오기
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");      //스트링으로 , 로 나눔
        if(row.size()) {
            int id = row[0].toInt();                //id값이 int 이므로 QString  변환
            Client* c = new Client(id, row[1], row[2], row[3]);
            ui->treeWidget->addTopLevelItem(c);
            clientList.insert(id, c);               //clientList에 값 넣기

            emit clientAdd(id,row[1]);
        }
    }
    file.close( );
    createConnection();
    queryModel = new QSqlTableModel;
    queryModel->setTable("clientDB");
    queryModel->select();

    queryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    queryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    queryModel->setHeaderData(2, Qt::Horizontal, QObject::tr("phoneNumber"));
    queryModel->setHeaderData(3, Qt::Horizontal, QObject::tr("address"));


    ui->tableView->setModel(queryModel);
}

ClientManagerForm::~ClientManagerForm()         //소멸자
{
    delete ui;                                  //ui닫기

    QFile file("clientlist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);                     //파일을 저장하기
    for (const auto& v : clientList) {
        Client* c = v;
        out << c->id() << ", " << c->getName() << ", ";
        out << c->getPhoneNumber() << ", ";
        out << c->getAddress() << "\n";
    }
    file.close( );
}

int ClientManagerForm::makeId( )        //id 값 설정
{
    if(clientList.size( ) == 0) {       // 값이 없으면 client id는 1부터 시작하게 return 값을 설정
        return 1;
    } else {
        auto id = clientList.lastKey();    //이전 값에 ++id 된 값으로 증가
        return ++id;
    }
}

void ClientManagerForm::showContextMenu(const QPoint &pos)      //마우스 위치 설정
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);

    menu->exec(globalPos);
}
void ClientManagerForm::showContextMenu1(const QPoint &pos)      //마우스 위치 설정
{
    QPoint globalPos = ui->tableView->mapToGlobal(pos);

    menu->exec(globalPos);
}

void ClientManagerForm::on_addPushButton_clicked()              //추가 버튼 눌렸을 때
{
    QString name, number, address;
    int id = makeId( );                                         //설정한 id값을 id에 대입
    name = ui->nameLineEdit->text();                            //입력한 값을 name에 대입
    number = ui->phoneNumberLineEdit->text();                   //입력한 값을 number에 대입
    address = ui->addressLineEdit->text();                      //입력한 값을 address에 대입
    if(name.length()) {
        Client* c = new Client(id, name, number, address);      //입력된 정보들을 clientList에 추가
        ui->treeWidget->addTopLevelItem(c);
        clientList.insert(id, c);
        emit clientAdd(id, name);
        QSqlQuery query;
        query.exec(QString("INSERT INTO clientDB VALUES (%1, '%2', '%3', '%4')").arg(id).arg(name).arg(number).arg(address));
        queryModel->select();
    }
    clearText();            //다음 입력값을 받기 위해 text에 입력했던 값을 지움

}
void ClientManagerForm::on_modifyPushButton_clicked()           //변경 버튼을 눌렸을 때
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();      //현재 treeWidget에 현재 정보를 item에 대입
    int index = ui->treeWidget->currentIndex().row();           //현재 정보들을 행으로 index에 대입
    if(item != nullptr) {                                       //아무것도 없을 때를 대비하여 예외 처리
        int key = item->text(0).toInt();                        //id값이 QString 형태이므로 변환 필요
        Client* c = clientList[key];                            //clientList에 있는 정보를 id 값으로 찾는다
        QString name, number, address;
        name = ui->nameLineEdit->text();
        number = ui->phoneNumberLineEdit->text();
        address = ui->addressLineEdit->text();
        c->setName(name);                       //clientList에 있는 name 값을 변경
        c->setPhoneNumber(number);              //clientList에 있는 phoneNumber 값을 변경
        c->setAddress(address);                 //clientList에 있는 address 값을 변경
        clientList[key] = c;
        emit clientModify(key,index,name);
        //dbAddclient();
        QSqlQuery query;
        query.exec(QString("INSERT INTO clientDB VALUES (%1, '%2', '%3', '%4')").arg(key).arg(name).arg(number).arg(address));
        queryModel->select();
    }
    clearText();            //다음 입력값을 받기 위해 text에 입력했던 값을 지움
}

void ClientManagerForm::removeItem()                //정보 삭제
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    int index = ui->treeWidget->currentIndex().row();
     QModelIndex ix = ui->tableView->currentIndex();
     int id =ix.sibling(ix.row(),0).data().toInt();

    if(item != nullptr) {
        clientList.remove(item->text(0).toInt());    //해당 id를 삭제
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
        ui->treeWidget->update();                  //treeWidget을 업데이트
        emit clientRemove(index);


//        QSqlQuery query;
//            query.prepare("DELETE FROM Customer WHERE c_id = ?;");
//            query.addBindValue(ID);
//            query.exec();
//            queryModel->select();
//        QModelIndexList indexes = ui->tableView->selectionModel()->selectedRows();
//            for(int i = indexes.count()-1; i>=0; i--)
//            {
//                ui->tableWidget->removeRow(indexes.at(i).row());
//            }
    }
    QSqlQuery query;
    query.prepare("DELETE FROM clientDB WHERE id = ?;");
    query.addBindValue(id);
    query.exec();
    queryModel->select();

//            ui->tableView->row == ui->tableView->indexAt(globalPos);
//                    indexAt(pos)
   // clearText();           //다음 입력값을 받기 위해 text에 입력했던 값을 지움
}


void ClientManagerForm::on_searchPushButton_clicked()       //찾기 버튼 눌렸을 때
{
    ui->searchTreeWidget->clear();                          //treeWidget을 정리
    //    for(int i = 0; i < ui->treeWidget->columnCount(); i++)
    int i = ui->searchComboBox->currentIndex();             //찾을 항목을 comboBox로 보여줌
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);        //일치하는 정보를 찾는다

        foreach(auto i, items) {
            Client* c = static_cast<Client*>(i);            //찾은 정보를 searchTreeWidget에 추가해줍니다
            int id = c->id();
            QString name = c->getName();
            QString number = c->getPhoneNumber();
            QString address = c->getAddress();
            Client* item = new Client(id, name, number, address);
            ui->searchTreeWidget->addTopLevelItem(item);

        }
    }
}


void ClientManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)        //등록된 정보를 눌렸을 때
{
    Q_UNUSED(column);       //column 사용하지 않는다는것을 알려준다. 적지 않아도 되지만 오류 메세지가 뜬다
    ui->idLineEdit->setText(item->text(0));             //선택한 정보를 lineEdit에 보여줍니다
    ui->nameLineEdit->setText(item->text(1));           //선택한 정보를 lineEdit에 보여줍니다
    ui->phoneNumberLineEdit->setText(item->text(2));    //선택한 정보를 lineEdit에 보여줍니다
    ui->addressLineEdit->setText(item->text(3));        //선택한 정보를 lineEdit에 보여줍니다
}


void ClientManagerForm::clientData(int key)         //client정보를 shopmanager에 해당하는 정보를 보내 줌
{
    Client * c =clientList[key];                    //map 사용으로 key로 해당 정보들을 찾음
    emit clientInfo(c->getName(),c->getPhoneNumber(),c->getAddress());
}
void ClientManagerForm::clearText()         //add,modify,remove버튼을 눌릴때 textLine을 지우기 위한 함수
//다음입력값을 받기 위해 textLineEdit를 지우는 함수
{
    ui->idLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->phoneNumberLineEdit->clear();
    ui->addressLineEdit->clear();
}
