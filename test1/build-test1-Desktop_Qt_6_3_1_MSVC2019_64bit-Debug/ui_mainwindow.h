/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_Quit;
    QAction *actionClient;
    QAction *actionProduct;
    QAction *actionShop_Info;
    QAction *actionShop;
    QAction *actionChat;
    QAction *actionChatServer_Info;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        actionClient = new QAction(MainWindow);
        actionClient->setObjectName(QString::fromUtf8("actionClient"));
        actionProduct = new QAction(MainWindow);
        actionProduct->setObjectName(QString::fromUtf8("actionProduct"));
        actionShop_Info = new QAction(MainWindow);
        actionShop_Info->setObjectName(QString::fromUtf8("actionShop_Info"));
        actionShop = new QAction(MainWindow);
        actionShop->setObjectName(QString::fromUtf8("actionShop"));
        actionChat = new QAction(MainWindow);
        actionChat->setObjectName(QString::fromUtf8("actionChat"));
        actionChatServer_Info = new QAction(MainWindow);
        actionChatServer_Info->setObjectName(QString::fromUtf8("actionChatServer_Info"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        mdiArea->setFocusPolicy(Qt::NoFocus);
        mdiArea->setFrameShape(QFrame::WinPanel);
        mdiArea->setFrameShadow(QFrame::Plain);
        mdiArea->setLineWidth(1);
        mdiArea->setMidLineWidth(0);
        mdiArea->setActivationOrder(QMdiArea::CreationOrder);
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);
        mdiArea->setTabsClosable(false);

        horizontalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Britannic Bold")});
        font.setPointSize(18);
        toolBar->setFont(font);
        toolBar->setMovable(true);
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Quit);
        menu_File->addSeparator();
        toolBar->addAction(actionClient);
        toolBar->addSeparator();
        toolBar->addAction(actionProduct);
        toolBar->addSeparator();
        toolBar->addAction(actionShop);
        toolBar->addSeparator();
        toolBar->addAction(actionChatServer_Info);
        toolBar->addSeparator();
        toolBar->addAction(actionChat);
        toolBar->addSeparator();
        toolBar->addAction(action_Quit);

        retranslateUi(MainWindow);
        QObject::connect(action_Quit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        action_Quit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        actionClient->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        actionProduct->setText(QCoreApplication::translate("MainWindow", "Product", nullptr));
        actionShop_Info->setText(QCoreApplication::translate("MainWindow", "Shop Info", nullptr));
        actionShop->setText(QCoreApplication::translate("MainWindow", "Shop", nullptr));
        actionChat->setText(QCoreApplication::translate("MainWindow", "Chat", nullptr));
        actionChatServer_Info->setText(QCoreApplication::translate("MainWindow", "ChatServer Info", nullptr));
#if QT_CONFIG(tooltip)
        mdiArea->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
#if QT_CONFIG(tooltip)
        toolBar->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
