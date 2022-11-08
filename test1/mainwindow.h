#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shopmanagerform.h"
#include "chatclientform.h"
////#include "chatserverform.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ClientManagerForm;
class ProductManagerForm;
class ShopManagerForm;
class ChatServerForm;
class ChatClientForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionClient_triggered();
    void on_actionProduct_triggered();
    void on_actionShop_triggered();
    void on_actionChat_triggered();

    void on_actionChatServer_Info_triggered();

private:
    Ui::MainWindow *ui;
    ClientManagerForm *clientForm;
    ProductManagerForm *productForm;
    ShopManagerForm *shopForm;
    ChatServerForm * chatServerForm;
    ChatClientForm * chatClientForm;

};
#endif // MAINWINDOW_H
