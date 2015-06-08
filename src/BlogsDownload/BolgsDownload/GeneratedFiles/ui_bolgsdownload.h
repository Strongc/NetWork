/********************************************************************************
** Form generated from reading UI file 'bolgsdownload.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOLGSDOWNLOAD_H
#define UI_BOLGSDOWNLOAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BolgsDownloadClass
{
public:

    void setupUi(QWidget *BolgsDownloadClass)
    {
        if (BolgsDownloadClass->objectName().isEmpty())
            BolgsDownloadClass->setObjectName(QString::fromUtf8("BolgsDownloadClass"));
        BolgsDownloadClass->resize(600, 400);

        retranslateUi(BolgsDownloadClass);

        QMetaObject::connectSlotsByName(BolgsDownloadClass);
    } // setupUi

    void retranslateUi(QWidget *BolgsDownloadClass)
    {
        BolgsDownloadClass->setWindowTitle(QApplication::translate("BolgsDownloadClass", "BolgsDownload", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BolgsDownloadClass: public Ui_BolgsDownloadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOLGSDOWNLOAD_H
