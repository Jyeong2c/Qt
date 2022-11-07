#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

static bool createConnection()
{
    //Database Layer
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("person.db"/*"person"*/);         //db 파일로 저장       파일명뒤에 .db랑 그냥 파일명만 적을 때 같다.
    //db.setDatabaseName(":memory:");       //파일로 저장 안되니깐 보안에 좋다 단점 - 저장 X
    if(!db.open())return false;
    //SQL Layer
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person(id INTEGER Primary Key,"      //primary 키가 존재하지 않으면
               "firstname VARCHAR(20) NOT NULL, lastname VARCHAR(20));");
    query.exec("INSERT INTO person VALUES(101,'Youngsu','Kang');");
    query.exec("INSERT INTO person (firstname, lastname) VALUES('Soomi','Kim')");
    query.exec("INSERT INTO person (firstname, lastname) VALUES"
               "('Hanmi','Lee'),('YoungJin','Suh'),('YoungHwa','Rye');");
//SQL LITE 에서는 비워두면 자동으로 ID 값이 채워진다
    return true;

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection()) return 1;

    //QSqlQueryModel queryModel;
    //queryModel.setQuery("select * from person");

    QSqlTableModel queryModel;
    queryModel.setTable("Person");
    //queryModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
    queryModel.select();

    queryModel.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    queryModel.setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    queryModel.setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));

    QTableView *tableview =new QTableView;
    tableview->setModel(&queryModel);
    tableview->setWindowTitle(QObject::tr("Query Model"));
    tableview->hideColumn(0);
    tableview->show();

//    MainWindow w;
//    w.show();
    return a.exec();
}
