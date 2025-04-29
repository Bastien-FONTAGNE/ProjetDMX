#include "Projet_DMX.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Projet_DMX w;
    w.show();
    return a.exec();
}
