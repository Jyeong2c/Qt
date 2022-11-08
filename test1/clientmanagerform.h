//#ifndef CLIENTMANAGERFORM_H
//#define CLIENTMANAGERFORM_H

//#include <QWidget>
//#include <QHash>

//#include "client.h"

//class QMenu;
//class QTreeWidgetItem;

//namespace Ui {
//class ClientManagerForm;
//}

//class ClientManagerForm : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit ClientManagerForm(QWidget *parent = nullptr);
//    ~ClientManagerForm();
//    void loadData();                            //파일 입출력

//private slots:
//    /* QTreeWidget을 위한 슬롯 */
//    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);      //고객정보 클릭시
//    void showContextMenu(const QPoint &);
//    void removeItem();                          //QAction을 위한 슬롯
//    void on_addPushButton_clicked();            //추가 버튼
//    void on_modifyPushButton_clicked();         //변경 버튼
//    void on_searchPushButton_clicked();         //찾기 버튼
//    void clientData(int );                      //고객 데이터

//signals:
//    void clientAdd(int , QString);              //추가버튼을 누를시 고객 정보 보내기 위해
//    void clientRemove(int);                     //삭제버튼을 누를시 삭제된 정보를 보내기 위해
//    void clientInfo(QString, QString, QString); //고객 정보 보내기 위해
//    void clientModify(int,int,QString);         //변경버튼을 누를시 변경된 고객 정보 보내기 위해




//private:
//    int makeId();                               //고객 ID 할당
//    QMap<int, Client*> clientList;              //고객정보를 QMap에 저장
//    Ui::ClientManagerForm *ui;                  //Ui이 생성
//    QMenu* menu;
//    void clearText();                           //다음 고객을 입력 받기 위해 입력창 지움
//};

//#endif // CLIENTMANAGERFORM_H

#ifndef CLIENTMANAGERFORM_H
#define CLIENTMANAGERFORM_H

#include <QWidget>
#include <QHash>
#include <QSqlQuery>

#include "client.h"

class QMenu;
class QTreeWidgetItem;
class QSqlQuery;
class QSqlTableModel;

namespace Ui {
class ClientManagerForm;
}

class ClientManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClientManagerForm(QWidget *parent = nullptr);
    ~ClientManagerForm();
    void loadData();                            //파일 입출력
    //void dbLoadData();

private slots:
    /* QTreeWidget을 위한 슬롯 */
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);      //고객정보 클릭시
    void showContextMenu(const QPoint &);
    void showContextMenu1(const QPoint &);
    void removeItem();                          //QAction을 위한 슬롯
    void on_addPushButton_clicked();            //추가 버튼
    void on_modifyPushButton_clicked();         //변경 버튼
    void on_searchPushButton_clicked();         //찾기 버튼
    void clientData(int );                      //고객 데이터
    //bool dbAddclient();
signals:
    void clientAdd(int , QString);              //추가버튼을 누를시 고객 정보 보내기 위해
    void clientRemove(int);                     //삭제버튼을 누를시 삭제된 정보를 보내기 위해
    void clientInfo(QString, QString, QString); //고객 정보 보내기 위해
    void clientModify(int,int,QString);         //변경버튼을 누를시 변경된 고객 정보 보내기 위해




private:
    int makeId();                               //고객 ID 할당
    QMap<int, Client*> clientList;              //고객정보를 QMap에 저장
    Ui::ClientManagerForm *ui;                  //Ui이 생성
    QMenu* menu;
    void clearText();                           //다음 고객을 입력 받기 위해 입력창 지움
    //QSqlQuery query;
    static bool createConnection();
    QSqlTableModel *queryModel;

};

#endif // CLIENTMANAGERFORM_H
