/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *doButton;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(850, 190);
        Widget->setMinimumSize(QSize(850, 190));
        Widget->setMaximumSize(QSize(850, 190));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 20, 591, 31));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(630, 20, 201, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        selectButton = new QPushButton(layoutWidget);
        selectButton->setObjectName("selectButton");

        horizontalLayout->addWidget(selectButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        doButton = new QPushButton(layoutWidget);
        doButton->setObjectName("doButton");

        horizontalLayout->addWidget(doButton);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 70, 811, 91));
        textEdit->setReadOnly(true);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(690, 160, 131, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\255\227\347\254\246\350\247\206\351\242\221\347\224\237\346\210\220\345\231\250", nullptr));
        selectButton->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        doButton->setText(QCoreApplication::translate("Widget", "\347\224\237\346\210\220", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">\346\234\213\345\217\213\345\234\210\347\232\204\345\220\204\344\275\215\346\234\213\345\217\213\344\273\254\346\226\260\345\271\264\345\277\253\344\271\220\357\274\201\346\226\260\347\232\204\344\270\200\345\271\264\351\207\214\347\245\235\344\275\240\344\273\254\357\274\232</span></p>\n"
"<p align=\"center\" style=\" margin"
                        "-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'consolas','lucida console','courier new','monospace'; font-size:18pt; font-weight:700; font-style:italic; color:#1f1f1f; background-color:#ffffff;\">\350\264\242\346\272\220\346\273\232\346\273\232\357\274\233\345\220\211\347\245\245\351\253\230\347\205\247\357\274\214\351\270\277\350\277\220\345\275\223\345\244\264\357\274\233\345\271\270\347\246\217\345\233\264\347\273\225\357\274\214\345\201\245\345\272\267\347\233\270\344\274\264\357\274\233\344\270\200\347\224\237\345\271\263\345\256\211\357\274\214</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'consolas','lucida console','courier new','monospace'; font-size:18pt; font-weight:700; font-style:italic; color:#1f1f1f; background-color:#ffffff;\">\344\270\207\344\272\213\351\241\272\345\277\203\357\274"
                        "\233\347\254\221\345\217\243\345\270\270\345\274\200\357\274\201</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Power by LiweSoftware", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
