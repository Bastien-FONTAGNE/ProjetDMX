#pragma once
/**********************************************************************************************
//* Programme : DMX.cpp                                          Date : 10/03/2025
//*--------------------------------------------------------------------------------------------
//* Programmeurs : Fatima Mahamat                                            Classe : BTSCIEL2
//*
//*--------------------------------------------------------------------------------------------
//* But : un prototype �tablissant un protocole de communication usb-s�rie avec une arduino et
//* un code c++
//* Programmes associ�s : .cpp
//*********************************************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_QtSerialPortTest.h"
#include <qserialport.h>
#include <QSerialPortInfo>

class QtSerialPortTest : public QMainWindow
{
    Q_OBJECT

public:
    QtSerialPortTest(QWidget* parent = nullptr);
    ~QtSerialPortTest();

private:
    Ui::QtSerialPortTestClass ui;
    QSerialPort* port;

public slots:
    void onOpenPortButtonClicked();
    void onSerialPortReadyRead();
    void onSendMessageButtonClicked();
};