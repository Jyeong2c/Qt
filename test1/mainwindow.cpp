#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientmanagerform.h"
#include "productmanagerform.h"
#include "shopmanagerform.h"
#include "chatclientform.h"
#include "chatserverform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shopForm = new ShopManagerForm(this);
    shopForm->setWindowTitle(tr("Shop Info"));          //Shop Info title생성
        connect(shopForm, SIGNAL(destroyed()),          //객체가 삭제하기 전에 시그널을 줌
                shopForm, SLOT(deleteLater()));         //객체를 삭제하도록 예약

    clientForm = new ClientManagerForm(this);
    clientForm->setWindowTitle(tr("Client Info"));      //client Info title생성
    connect(clientForm, SIGNAL(destroyed()),            //객체가 삭제하기 전에 시그널을 줌
            clientForm, SLOT(deleteLater()));           //객체를 삭제하도록 예약

    productForm = new ProductManagerForm(this);
    productForm->setWindowTitle(tr("Product Info"));    //Product Info title생성
    connect(productForm, SIGNAL(destroyed()),           //객체가 삭제하기 전에 시그널을 줌
            productForm, SLOT(deleteLater()));          //객체를 삭제하도록 예약


    connect(clientForm,SIGNAL(clientAdd(int,QString)),               //clientmanager 클래스에 있는 제품명을 찾아
            shopForm,SLOT(clientName(int,QString)));                 //shopmanagerform comboBox에 이름 추가
    connect(clientForm,SIGNAL(clientModify(int ,int , QString)),     //고객정보가 변경될 때 comboBox에 고객정보 변경
            shopForm,SLOT(clientNameModify(int ,int , QString)));
    connect(clientForm, SIGNAL(clientRemove(int)),                   //고객이 제거 될때  comboBox에 이름 제거
            shopForm, SLOT(clientNameRemove(int)));


    //clientlist에 있는 값을 key값으로 찾아서 정보를 보내준다
    connect(shopForm,SIGNAL(clientAddUpdate(int)),
            clientForm,SLOT(clientData(int)));

    //clientData안에서 clientInfo 시그널을 줌으로써 shopmanager에서 clientTreeWidget에 보여주기 위한 connect
    connect(clientForm,SIGNAL(clientInfo(QString,QString,QString)),
            shopForm,SLOT(clientAddUpdate(QString,QString,QString)));




    connect(productForm,SIGNAL(productAdd(int,QString)),              //productmanager 클래스에 있는 제품명을 찾아
            shopForm,SLOT(productName(int,QString)));                 //shopmanagerform comboBox에 제품명 추가
    connect(productForm,SIGNAL(productRemove(int)),                   //제품이 제거 될때  comboBox에 이름 제거
            shopForm,SLOT(productNameRemove(int)));
    connect(productForm,SIGNAL(productModify(int ,int , QString)),    //제품정보가 변경될 때 comboBox에 고객정보 변경
            shopForm,SLOT(productNameModify(int ,int , QString)));

    connect(shopForm,SIGNAL(productAddUpdate(int)),                               //productlist에 있는 값을 key값으로 찾아서 정보를 보내준다
            productForm,SLOT(productData(int)));

    connect(productForm,SIGNAL(productInfo(QString,QString,QString,QString)),     //productData안에서 productInfo 시그널을 줌으로써
            shopForm,SLOT(productAddUpdate(QString,QString,QString,QString)));    //shopmanager에서 productTreeWidget에 보여주기 위한 connect



    chatServerForm = new ChatServerForm(this);
    chatServerForm->setWindowTitle(tr("Chat Info"));                    //Chat Info title생성
    connect(chatServerForm, SIGNAL(destroyed()),                        //객체가 삭제하기 전에 시그널을 줌
            chatServerForm, SLOT(deleteLater()));                       //객체를 삭제하도록 예약

    connect(clientForm,SIGNAL(clientAdd(int , QString)),                //client에 있는 고객 정보를 server clientList에 추가
            chatServerForm,SLOT(addClient(int, QString)));

    connect(clientForm,SIGNAL(clientModify(int,int,QString)),           //client 정보가 변화 할 때 chatServerform에 있는
            chatServerForm,SLOT(modifyClientList(int,int,QString)));    //clientList 정보도 바뀐다

    connect(clientForm,SIGNAL(clientRemove(int)),                       //clietn 정보가 삭제되면 chatServerForm에 있는 client 정보도 삭제된다
            chatServerForm,SLOT(removeClientList(int)));


    clientForm->loadData();
    productForm->loadData();
    shopForm->loadData();
    //clientForm->dbLoadData();

    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(clientForm);          //mdiArea에서 viewMode를 tabbedView로 하여 clientForm을 보여줌
    ui->mdiArea->addSubWindow(productForm);                             //tab으로 productForm을 보여줌
    ui->mdiArea->addSubWindow(shopForm);                                //tab으로 shopForm을 보여줌
    ui->mdiArea->addSubWindow(chatServerForm);                          //tab으로 chatServerForm을 보여줌
    ui->mdiArea->setActiveSubWindow(cw);                                //창을 활성화
}

MainWindow::~MainWindow()       //메인 윈도우 소멸자
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()                   //toolBar에 있는 Client을 눌렸을 때 clientForm로 이동
{
    if(clientForm != nullptr) {
        clientForm->setFocus();
    }
}
void MainWindow::on_actionProduct_triggered()                  //toolBar에 있는 Product를 눌렸을 때 productForm로 이동
{
    if(productForm != nullptr) {

        productForm->setFocus();
    }
}
void MainWindow::on_actionChatServer_Info_triggered()          //toolBar에 있는 ChatInfo를 눌렸을 때 chatServer로 이동
{
    if(chatServerForm != nullptr){
        chatServerForm->setFocus();
    }
}
void MainWindow::on_actionShop_triggered()                     //toolBar에 있는 Shop을 눌렸을 때 shopForm로 이동
{
    if(shopForm != nullptr) {
        shopForm->setFocus();
    }
}

void MainWindow::on_actionChat_triggered()                       //toolBar에 있는 Chat을 눌렸을 때
{
    chatClientForm = new ChatClientForm(nullptr);
    chatClientForm ->show();                                     //chatClient 창이 새로 열림
    connect(chatClientForm,SIGNAL(sendClientName(QString)),      //login 시 시그널을 보냄
            chatServerForm,SLOT(clientNameSended(QString)));     //servere단에 있는 고객 이름과 chatClientForm에서 보내온 data값이 같은지 확인합니다
    connect(chatServerForm,SIGNAL(sendFlag(int)),                //위에서 data 값이 일치하지 확인하고 flag값을 시그널 값을 보냄
            chatClientForm,SLOT(flagSended(int)));               //flag신호를 받습니다
}



