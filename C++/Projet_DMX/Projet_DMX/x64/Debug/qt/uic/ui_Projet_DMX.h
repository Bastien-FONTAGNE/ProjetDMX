/********************************************************************************
** Form generated from reading UI file 'Projet_DMX.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJET_DMX_H
#define UI_PROJET_DMX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Projet_DMXClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Projet_DMXClass)
    {
        if (Projet_DMXClass->objectName().isEmpty())
            Projet_DMXClass->setObjectName(QString::fromUtf8("Projet_DMXClass"));
        Projet_DMXClass->resize(600, 400);
        menuBar = new QMenuBar(Projet_DMXClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Projet_DMXClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Projet_DMXClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Projet_DMXClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Projet_DMXClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Projet_DMXClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Projet_DMXClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Projet_DMXClass->setStatusBar(statusBar);

        retranslateUi(Projet_DMXClass);

        QMetaObject::connectSlotsByName(Projet_DMXClass);
    } // setupUi

    void retranslateUi(QMainWindow *Projet_DMXClass)
    {
        Projet_DMXClass->setWindowTitle(QCoreApplication::translate("Projet_DMXClass", "Projet_DMX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Projet_DMXClass: public Ui_Projet_DMXClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJET_DMX_H
