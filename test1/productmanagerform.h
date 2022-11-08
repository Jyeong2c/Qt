#ifndef PRODUCTMANAGERFORM_H
#define PRODUCTMANAGERFORM_H

#include <QWidget>
#include <QHash>

#include "product.h"

class QMenu;
class QTreeWidgetItem;

namespace Ui {
class ProductManagerForm;
}

class ProductManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagerForm(QWidget *parent = nullptr);
    ~ProductManagerForm();
    void loadData();
   // QList<Product*> getProducts();
private slots:
    /* QTreeWidget을 위한 슬롯 */
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void showContextMenu(const QPoint &);
    void removeItem();              /* QAction을 위한 슬롯 */
    void on_addPushButton_clicked();
    void on_modifyPushButton_clicked();
    void on_searchPushButton_clicked();
    void productData(int);

signals:
    void productAdd(int, QString);
    void productRemove(int);
    void productModify(int,int,QString);
    void productInfo(QString, QString, QString, QString);
    void productTotal(QString);
    //=======================
//    void productAddQuantity(int ,QString);
//    void QuantityModify(int, QString);
//    void prQuantity(QString);

private:
    int makeId();

    QMap<int, Product*> productList;
    Ui::ProductManagerForm *ui;
    QMenu* menu;
    void clearText();


};

#endif // PRODUCTMANAGERFORM_H

