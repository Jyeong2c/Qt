/********************************************************************************
** Form generated from reading UI file 'shopmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPMANAGERFORM_H
#define UI_SHOPMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopManagerForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *listVerticalLayout;
    QTreeWidget *treeWidget;
    QToolBox *toolBox;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout_10;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QVBoxLayout *verticalLayout_9;
    QLabel *clientIdLabel;
    QComboBox *clientIdcomboBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *productNameLabel;
    QComboBox *productNamecomboBox;
    QVBoxLayout *verticalLayout_8;
    QLabel *priceLabel;
    QLineEdit *priceLineEdit;
    QSplitter *splitter_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *amountLabel;
    QLineEdit *amountLineEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_7;
    QLabel *discountLabel;
    QLineEdit *discountLineEdit;
    QLabel *totalPriceLabel;
    QLineEdit *totalPriceLineEdit;
    QHBoxLayout *addHorizontalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QSplitter *splitter_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeWidget *clientTreeWidget;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QTreeWidget *productTreeWidget;
    QWidget *searchPage;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *searchTreeWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchPushButton;

    void setupUi(QWidget *ShopManagerForm)
    {
        if (ShopManagerForm->objectName().isEmpty())
            ShopManagerForm->setObjectName(QString::fromUtf8("ShopManagerForm"));
        ShopManagerForm->resize(579, 371);
        verticalLayout_2 = new QVBoxLayout(ShopManagerForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(ShopManagerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        listVerticalLayout = new QVBoxLayout(layoutWidget);
        listVerticalLayout->setObjectName(QString::fromUtf8("listVerticalLayout"));
        listVerticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(layoutWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setRootIsDecorated(false);

        listVerticalLayout->addWidget(treeWidget);

        splitter->addWidget(layoutWidget);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        inputPage = new QWidget();
        inputPage->setObjectName(QString::fromUtf8("inputPage"));
        inputPage->setGeometry(QRect(0, 0, 361, 323));
        verticalLayout_10 = new QVBoxLayout(inputPage);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        idLabel = new QLabel(inputPage);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        verticalLayout_10->addWidget(idLabel);

        idLineEdit = new QLineEdit(inputPage);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setReadOnly(true);

        verticalLayout_10->addWidget(idLineEdit);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        clientIdLabel = new QLabel(inputPage);
        clientIdLabel->setObjectName(QString::fromUtf8("clientIdLabel"));

        verticalLayout_9->addWidget(clientIdLabel);

        clientIdcomboBox = new QComboBox(inputPage);
        clientIdcomboBox->setObjectName(QString::fromUtf8("clientIdcomboBox"));
        clientIdcomboBox->setEnabled(true);

        verticalLayout_9->addWidget(clientIdcomboBox);


        verticalLayout_10->addLayout(verticalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        productNameLabel = new QLabel(inputPage);
        productNameLabel->setObjectName(QString::fromUtf8("productNameLabel"));

        verticalLayout_5->addWidget(productNameLabel);

        productNamecomboBox = new QComboBox(inputPage);
        productNamecomboBox->setObjectName(QString::fromUtf8("productNamecomboBox"));

        verticalLayout_5->addWidget(productNamecomboBox);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        priceLabel = new QLabel(inputPage);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));

        verticalLayout_8->addWidget(priceLabel);

        priceLineEdit = new QLineEdit(inputPage);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));
        priceLineEdit->setReadOnly(true);

        verticalLayout_8->addWidget(priceLineEdit);


        horizontalLayout_3->addLayout(verticalLayout_8);


        verticalLayout_10->addLayout(horizontalLayout_3);

        splitter_3 = new QSplitter(inputPage);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(splitter_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        amountLabel = new QLabel(layoutWidget1);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));

        verticalLayout_6->addWidget(amountLabel);

        amountLineEdit = new QLineEdit(layoutWidget1);
        amountLineEdit->setObjectName(QString::fromUtf8("amountLineEdit"));

        verticalLayout_6->addWidget(amountLineEdit);

        splitter_3->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout_7 = new QVBoxLayout(layoutWidget2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        discountLabel = new QLabel(layoutWidget2);
        discountLabel->setObjectName(QString::fromUtf8("discountLabel"));

        verticalLayout_7->addWidget(discountLabel);

        discountLineEdit = new QLineEdit(layoutWidget2);
        discountLineEdit->setObjectName(QString::fromUtf8("discountLineEdit"));

        verticalLayout_7->addWidget(discountLineEdit);

        splitter_3->addWidget(layoutWidget2);

        verticalLayout_10->addWidget(splitter_3);

        totalPriceLabel = new QLabel(inputPage);
        totalPriceLabel->setObjectName(QString::fromUtf8("totalPriceLabel"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\355\234\264\353\250\274\353\221\245\352\267\274\355\227\244\353\223\234\353\235\274\354\235\270")});
        font.setPointSize(10);
        totalPriceLabel->setFont(font);

        verticalLayout_10->addWidget(totalPriceLabel);

        totalPriceLineEdit = new QLineEdit(inputPage);
        totalPriceLineEdit->setObjectName(QString::fromUtf8("totalPriceLineEdit"));
        totalPriceLineEdit->setEnabled(true);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\355\234\264\353\250\274\353\221\245\352\267\274\355\227\244\353\223\234\353\235\274\354\235\270")});
        font1.setPointSize(11);
        totalPriceLineEdit->setFont(font1);
        totalPriceLineEdit->setReadOnly(true);

        verticalLayout_10->addWidget(totalPriceLineEdit);

        addHorizontalLayout = new QHBoxLayout();
        addHorizontalLayout->setObjectName(QString::fromUtf8("addHorizontalLayout"));
        addPushButton = new QPushButton(inputPage);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        addHorizontalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(inputPage);
        modifyPushButton->setObjectName(QString::fromUtf8("modifyPushButton"));

        addHorizontalLayout->addWidget(modifyPushButton);


        verticalLayout_10->addLayout(addHorizontalLayout);

        splitter_2 = new QSplitter(inputPage);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget3 = new QWidget(splitter_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\355\234\264\353\250\274\353\221\245\352\267\274\355\227\244\353\223\234\353\235\274\354\235\270")});
        font2.setPointSize(10);
        font2.setBold(false);
        label->setFont(font2);

        verticalLayout->addWidget(label);

        clientTreeWidget = new QTreeWidget(layoutWidget3);
        clientTreeWidget->setObjectName(QString::fromUtf8("clientTreeWidget"));
        clientTreeWidget->setHeaderHidden(false);
        clientTreeWidget->header()->setVisible(true);

        verticalLayout->addWidget(clientTreeWidget);

        splitter_2->addWidget(layoutWidget3);
        layoutWidget4 = new QWidget(splitter_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        verticalLayout_4->addWidget(label_2);

        productTreeWidget = new QTreeWidget(layoutWidget4);
        productTreeWidget->setObjectName(QString::fromUtf8("productTreeWidget"));

        verticalLayout_4->addWidget(productTreeWidget);

        splitter_2->addWidget(layoutWidget4);

        verticalLayout_10->addWidget(splitter_2);

        toolBox->addItem(inputPage, QString::fromUtf8("&Input"));
        searchPage = new QWidget();
        searchPage->setObjectName(QString::fromUtf8("searchPage"));
        searchPage->setGeometry(QRect(0, 0, 361, 323));
        verticalLayout_3 = new QVBoxLayout(searchPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchTreeWidget = new QTreeWidget(searchPage);
        searchTreeWidget->setObjectName(QString::fromUtf8("searchTreeWidget"));
        searchTreeWidget->setRootIsDecorated(false);

        verticalLayout_3->addWidget(searchTreeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchComboBox = new QComboBox(searchPage);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName(QString::fromUtf8("searchComboBox"));

        horizontalLayout->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(searchPage);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        searchPushButton = new QPushButton(searchPage);
        searchPushButton->setObjectName(QString::fromUtf8("searchPushButton"));

        verticalLayout_3->addWidget(searchPushButton);

        toolBox->addItem(searchPage, QString::fromUtf8("&Search"));
        splitter->addWidget(toolBox);

        verticalLayout_2->addWidget(splitter);

#if QT_CONFIG(shortcut)
        idLabel->setBuddy(idLineEdit);
        clientIdLabel->setBuddy(clientIdcomboBox);
        productNameLabel->setBuddy(productNamecomboBox);
        priceLabel->setBuddy(priceLineEdit);
        amountLabel->setBuddy(amountLineEdit);
        discountLabel->setBuddy(discountLineEdit);
        totalPriceLabel->setBuddy(totalPriceLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ShopManagerForm);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ShopManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ShopManagerForm)
    {
        ShopManagerForm->setWindowTitle(QCoreApplication::translate("ShopManagerForm", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(7, QCoreApplication::translate("ShopManagerForm", "TotalProce", nullptr));
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("ShopManagerForm", "Discount", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("ShopManagerForm", "Amount", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("ShopManagerForm", "Date", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ShopManagerForm", "ClientName", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        idLabel->setText(QCoreApplication::translate("ShopManagerForm", "I&D", nullptr));
        clientIdLabel->setText(QCoreApplication::translate("ShopManagerForm", "ClientID", nullptr));
        productNameLabel->setText(QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        priceLabel->setText(QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        amountLabel->setText(QCoreApplication::translate("ShopManagerForm", "&Amount", nullptr));
        discountLabel->setText(QCoreApplication::translate("ShopManagerForm", "&Discount", nullptr));
        totalPriceLabel->setText(QCoreApplication::translate("ShopManagerForm", "&TotalPrice", nullptr));
        addPushButton->setText(QCoreApplication::translate("ShopManagerForm", "&Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ShopManagerForm", "&Modify", nullptr));
        label->setText(QCoreApplication::translate("ShopManagerForm", "Client Info", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = clientTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ShopManagerForm", "Address", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ShopManagerForm", "PhoneNumber", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ShopManagerForm", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("ShopManagerForm", "Product Info", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = productTreeWidget->headerItem();
        ___qtreewidgetitem2->setText(3, QCoreApplication::translate("ShopManagerForm", "Country", nullptr));
        ___qtreewidgetitem2->setText(2, QCoreApplication::translate("ShopManagerForm", "Count", nullptr));
        ___qtreewidgetitem2->setText(1, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ShopManagerForm", "&Input", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = searchTreeWidget->headerItem();
        ___qtreewidgetitem3->setText(7, QCoreApplication::translate("ShopManagerForm", "TotalPrice", nullptr));
        ___qtreewidgetitem3->setText(6, QCoreApplication::translate("ShopManagerForm", "Discount", nullptr));
        ___qtreewidgetitem3->setText(5, QCoreApplication::translate("ShopManagerForm", "Amount", nullptr));
        ___qtreewidgetitem3->setText(4, QCoreApplication::translate("ShopManagerForm", "Date", nullptr));
        ___qtreewidgetitem3->setText(3, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        ___qtreewidgetitem3->setText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem3->setText(1, QCoreApplication::translate("ShopManagerForm", "ClientName", nullptr));
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ShopManagerForm", "ClinetName", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        searchComboBox->setItemText(4, QCoreApplication::translate("ShopManagerForm", "Date", nullptr));
        searchComboBox->setItemText(5, QCoreApplication::translate("ShopManagerForm", "Amount", nullptr));
        searchComboBox->setItemText(6, QCoreApplication::translate("ShopManagerForm", "Discount", nullptr));
        searchComboBox->setItemText(7, QCoreApplication::translate("ShopManagerForm", "TotalPrice", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ShopManagerForm", "S&earch", nullptr));
        toolBox->setItemText(toolBox->indexOf(searchPage), QCoreApplication::translate("ShopManagerForm", "&Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopManagerForm: public Ui_ShopManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPMANAGERFORM_H
