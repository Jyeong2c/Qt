/********************************************************************************
** Form generated from reading UI file 'productmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTMANAGERFORM_H
#define UI_PRODUCTMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManagerForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *listVerticalLayout;
    QTreeWidget *treeWidget;
    QToolBox *toolBox;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout;
    QFormLayout *clientFormLayout;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QLabel *productNameLabel;
    QLineEdit *productNameLineEdit;
    QLabel *priceLabel;
    QLineEdit *priceLineEdit;
    QLabel *quantityLabel;
    QLineEdit *quantityLineEdit;
    QLabel *countryLabel;
    QLineEdit *countryLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *addHorizontalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QWidget *searchPage;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *searchTreeWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchPushButton;

    void setupUi(QWidget *ProductManagerForm)
    {
        if (ProductManagerForm->objectName().isEmpty())
            ProductManagerForm->setObjectName(QString::fromUtf8("ProductManagerForm"));
        ProductManagerForm->resize(383, 300);
        verticalLayout_2 = new QVBoxLayout(ProductManagerForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(ProductManagerForm);
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
        inputPage->setGeometry(QRect(0, 0, 194, 252));
        verticalLayout = new QVBoxLayout(inputPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        clientFormLayout = new QFormLayout();
        clientFormLayout->setObjectName(QString::fromUtf8("clientFormLayout"));
        idLabel = new QLabel(inputPage);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));

        clientFormLayout->setWidget(0, QFormLayout::LabelRole, idLabel);

        idLineEdit = new QLineEdit(inputPage);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setReadOnly(true);

        clientFormLayout->setWidget(0, QFormLayout::FieldRole, idLineEdit);

        productNameLabel = new QLabel(inputPage);
        productNameLabel->setObjectName(QString::fromUtf8("productNameLabel"));

        clientFormLayout->setWidget(1, QFormLayout::LabelRole, productNameLabel);

        productNameLineEdit = new QLineEdit(inputPage);
        productNameLineEdit->setObjectName(QString::fromUtf8("productNameLineEdit"));

        clientFormLayout->setWidget(1, QFormLayout::FieldRole, productNameLineEdit);

        priceLabel = new QLabel(inputPage);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));

        clientFormLayout->setWidget(2, QFormLayout::LabelRole, priceLabel);

        priceLineEdit = new QLineEdit(inputPage);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));

        clientFormLayout->setWidget(2, QFormLayout::FieldRole, priceLineEdit);

        quantityLabel = new QLabel(inputPage);
        quantityLabel->setObjectName(QString::fromUtf8("quantityLabel"));

        clientFormLayout->setWidget(3, QFormLayout::LabelRole, quantityLabel);

        quantityLineEdit = new QLineEdit(inputPage);
        quantityLineEdit->setObjectName(QString::fromUtf8("quantityLineEdit"));

        clientFormLayout->setWidget(3, QFormLayout::FieldRole, quantityLineEdit);

        countryLabel = new QLabel(inputPage);
        countryLabel->setObjectName(QString::fromUtf8("countryLabel"));

        clientFormLayout->setWidget(4, QFormLayout::LabelRole, countryLabel);

        countryLineEdit = new QLineEdit(inputPage);
        countryLineEdit->setObjectName(QString::fromUtf8("countryLineEdit"));

        clientFormLayout->setWidget(4, QFormLayout::FieldRole, countryLineEdit);


        verticalLayout->addLayout(clientFormLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        addHorizontalLayout = new QHBoxLayout();
        addHorizontalLayout->setObjectName(QString::fromUtf8("addHorizontalLayout"));
        addPushButton = new QPushButton(inputPage);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        addHorizontalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(inputPage);
        modifyPushButton->setObjectName(QString::fromUtf8("modifyPushButton"));

        addHorizontalLayout->addWidget(modifyPushButton);


        verticalLayout->addLayout(addHorizontalLayout);

        toolBox->addItem(inputPage, QString::fromUtf8("&Input"));
        searchPage = new QWidget();
        searchPage->setObjectName(QString::fromUtf8("searchPage"));
        searchPage->setGeometry(QRect(0, 0, 194, 252));
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
        productNameLabel->setBuddy(productNameLineEdit);
        priceLabel->setBuddy(priceLineEdit);
        quantityLabel->setBuddy(quantityLineEdit);
        countryLabel->setBuddy(countryLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ProductManagerForm);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ProductManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ProductManagerForm)
    {
        ProductManagerForm->setWindowTitle(QCoreApplication::translate("ProductManagerForm", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("ProductManagerForm", "Country", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ProductManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ProductManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        idLabel->setText(QCoreApplication::translate("ProductManagerForm", "I&D", nullptr));
        productNameLabel->setText(QCoreApplication::translate("ProductManagerForm", "&ProductName", nullptr));
        priceLabel->setText(QCoreApplication::translate("ProductManagerForm", "P&rice", nullptr));
        quantityLabel->setText(QCoreApplication::translate("ProductManagerForm", "Quantity", nullptr));
        countryLabel->setText(QCoreApplication::translate("ProductManagerForm", "C&ountry", nullptr));
        addPushButton->setText(QCoreApplication::translate("ProductManagerForm", "&Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ProductManagerForm", "&Modify", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ProductManagerForm", "&Input", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = searchTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(4, QCoreApplication::translate("ProductManagerForm", "Country", nullptr));
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("ProductManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ProductManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ProductManagerForm", "PriceName", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ProductManagerForm", "Quantity", nullptr));
        searchComboBox->setItemText(4, QCoreApplication::translate("ProductManagerForm", "Country", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ProductManagerForm", "S&earch", nullptr));
        toolBox->setItemText(toolBox->indexOf(searchPage), QCoreApplication::translate("ProductManagerForm", "&Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagerForm: public Ui_ProductManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGERFORM_H
