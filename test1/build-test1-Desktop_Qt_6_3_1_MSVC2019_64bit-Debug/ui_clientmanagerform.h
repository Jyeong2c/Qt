/********************************************************************************
** Form generated from reading UI file 'clientmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMANAGERFORM_H
#define UI_CLIENTMANAGERFORM_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientManagerForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QTableView *tableView;
    QToolBox *toolBox;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout;
    QFormLayout *clientFormLayout;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *phoneNumberLabel;
    QLineEdit *phoneNumberLineEdit;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
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

    void setupUi(QWidget *ClientManagerForm)
    {
        if (ClientManagerForm->objectName().isEmpty())
            ClientManagerForm->setObjectName(QString::fromUtf8("ClientManagerForm"));
        ClientManagerForm->resize(647, 385);
        horizontalLayout_2 = new QHBoxLayout(ClientManagerForm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter_2 = new QSplitter(ClientManagerForm);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        treeWidget = new QTreeWidget(splitter);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setRootIsDecorated(false);
        splitter->addWidget(treeWidget);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        splitter->addWidget(tableView);
        splitter_2->addWidget(splitter);
        toolBox = new QToolBox(splitter_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        inputPage = new QWidget();
        inputPage->setObjectName(QString::fromUtf8("inputPage"));
        inputPage->setGeometry(QRect(0, 0, 249, 325));
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

        nameLabel = new QLabel(inputPage);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        clientFormLayout->setWidget(1, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(inputPage);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        clientFormLayout->setWidget(1, QFormLayout::FieldRole, nameLineEdit);

        phoneNumberLabel = new QLabel(inputPage);
        phoneNumberLabel->setObjectName(QString::fromUtf8("phoneNumberLabel"));

        clientFormLayout->setWidget(2, QFormLayout::LabelRole, phoneNumberLabel);

        phoneNumberLineEdit = new QLineEdit(inputPage);
        phoneNumberLineEdit->setObjectName(QString::fromUtf8("phoneNumberLineEdit"));

        clientFormLayout->setWidget(2, QFormLayout::FieldRole, phoneNumberLineEdit);

        addressLabel = new QLabel(inputPage);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        clientFormLayout->setWidget(3, QFormLayout::LabelRole, addressLabel);

        addressLineEdit = new QLineEdit(inputPage);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));

        clientFormLayout->setWidget(3, QFormLayout::FieldRole, addressLineEdit);


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
        searchPage->setGeometry(QRect(0, 0, 249, 325));
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
        splitter_2->addWidget(toolBox);

        horizontalLayout_2->addWidget(splitter_2);

#if QT_CONFIG(shortcut)
        idLabel->setBuddy(idLineEdit);
        nameLabel->setBuddy(nameLineEdit);
        phoneNumberLabel->setBuddy(phoneNumberLineEdit);
        addressLabel->setBuddy(addressLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ClientManagerForm);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ClientManagerForm)
    {
        ClientManagerForm->setWindowTitle(QCoreApplication::translate("ClientManagerForm", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ClientManagerForm", "Phone Number", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        idLabel->setText(QCoreApplication::translate("ClientManagerForm", "I&D", nullptr));
        nameLabel->setText(QCoreApplication::translate("ClientManagerForm", "&Name", nullptr));
        phoneNumberLabel->setText(QCoreApplication::translate("ClientManagerForm", "&Phone Number", nullptr));
        phoneNumberLineEdit->setInputMask(QCoreApplication::translate("ClientManagerForm", "999-0000-9999", nullptr));
        addressLabel->setText(QCoreApplication::translate("ClientManagerForm", "&Address", nullptr));
        addPushButton->setText(QCoreApplication::translate("ClientManagerForm", "&Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ClientManagerForm", "&Modify", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ClientManagerForm", "&Input", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = searchTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ClientManagerForm", "Phone Number", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ClientManagerForm", "Phone Number", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ClientManagerForm", "S&earch", nullptr));
        toolBox->setItemText(toolBox->indexOf(searchPage), QCoreApplication::translate("ClientManagerForm", "&Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientManagerForm: public Ui_ClientManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMANAGERFORM_H
