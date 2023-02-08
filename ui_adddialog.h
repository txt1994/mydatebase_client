/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *Btn_add_file;
    QLineEdit *sql_file_path;
    QPushButton *Btn_add_file_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_TextConnect;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_ok;
    QPushButton *Btn_cancel;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QString::fromUtf8("AddDialog"));
        AddDialog->resize(487, 276);
        gridLayout_3 = new QGridLayout(AddDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(AddDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(AddDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Btn_add_file = new QPushButton(groupBox);
        Btn_add_file->setObjectName(QString::fromUtf8("Btn_add_file"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/add-fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_add_file->setIcon(icon);
        Btn_add_file->setIconSize(QSize(27, 27));

        gridLayout->addWidget(Btn_add_file, 0, 1, 1, 1);

        sql_file_path = new QLineEdit(groupBox);
        sql_file_path->setObjectName(QString::fromUtf8("sql_file_path"));

        gridLayout->addWidget(sql_file_path, 0, 0, 1, 1);

        Btn_add_file_2 = new QPushButton(groupBox);
        Btn_add_file_2->setObjectName(QString::fromUtf8("Btn_add_file_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_add_file_2->setIcon(icon1);
        Btn_add_file_2->setIconSize(QSize(27, 27));

        gridLayout->addWidget(Btn_add_file_2, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Btn_TextConnect = new QPushButton(AddDialog);
        Btn_TextConnect->setObjectName(QString::fromUtf8("Btn_TextConnect"));

        horizontalLayout->addWidget(Btn_TextConnect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_ok = new QPushButton(AddDialog);
        Btn_ok->setObjectName(QString::fromUtf8("Btn_ok"));

        horizontalLayout->addWidget(Btn_ok);

        Btn_cancel = new QPushButton(AddDialog);
        Btn_cancel->setObjectName(QString::fromUtf8("Btn_cancel"));

        horizontalLayout->addWidget(Btn_cancel);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(AddDialog);

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QCoreApplication::translate("AddDialog", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("AddDialog", " \346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AddDialog", "SQLite 3", nullptr));

        groupBox->setTitle(QCoreApplication::translate("AddDialog", "\346\226\207\344\273\266", nullptr));
        Btn_add_file->setText(QString());
        Btn_add_file_2->setText(QString());
        Btn_TextConnect->setText(QCoreApplication::translate("AddDialog", "\346\265\213\350\257\225\350\277\236\346\216\245", nullptr));
        Btn_ok->setText(QCoreApplication::translate("AddDialog", "\347\241\256\345\256\232", nullptr));
        Btn_cancel->setText(QCoreApplication::translate("AddDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
