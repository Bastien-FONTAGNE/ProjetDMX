#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Projet_DMX.h"

class Projet_DMX : public QMainWindow
{
    Q_OBJECT

public:
    Projet_DMX(QWidget *parent = nullptr);
    ~Projet_DMX();

private:
    Ui::Projet_DMXClass ui;
};
