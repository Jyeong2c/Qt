#ifndef SHOPMANAGERFORM_H
#define SHOPMANAGERFORM_H

#include <QWidget>
#include <QHash>

#include "shop.h"

class QMenu;
class QTreeWidgetItem;
class QStrig;

namespace Ui {
class ShopManagerForm;
}

class ShopManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShopManagerForm(QWidget *parent = nullptr );
    ~ShopManagerForm();
    void loadData();

private slots:
    /* QTreeWidget을 위한 슬롯 */
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void showContextMenu(const QPoint &);
    void removeItem();              /* QAction을 위한 슬롯 */
    void on_addPushButton_clicked();
    void on_modifyPushButton_clicked();
    void on_searchPushButton_clicked();
    void clientName(int, QString);
    void clientAddUpdate(QString,QString,QString);
    void on_clientIdcomboBox_currentIndexChanged(int index);

    void productName(int, QString);
    void clientNameRemove(int);
    void clientNameModify(int ,int , QString);

    void productNameRemove(int);
    void productNameModify(int ,int , QString);

    void productAddUpdate(QString,QString,QString,QString);
    void on_productNamecomboBox_currentIndexChanged(int index);

    void on_discountLineEdit_textChanged(const QString &arg1);

    void on_amountLineEdit_textChanged(const QString &arg1);

signals:

    void clientAddUpdate(int);
    void productAddUpdate(int);



private:
    int makeId();
    Ui::ShopManagerForm *ui;
    QMap<int, Shop*> shopList;
    QMenu* menu;
   //QString total();
    QList<int> clientIDList;
    QList<int> productIDList;

};

#endif // SHOPMANAGERFORM_H
