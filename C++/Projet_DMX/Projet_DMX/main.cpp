#include <QCoreApplication>
#include <QApplication>
#include <QDebug>
#include <Qtsql/qsqldatabase.h>
#include <QtSql/qsqlerror.h>
#include <iostream>
#include <iomanip>
#include <QtWidgets/QMainWindow>
#include "Channel.h"
#include "channelvalues.h"
#include "configurationtrame.h"
#include "DMX.h"
#include "Equipment.h"
#include "Scene.h"
#include "TrameManager.h"
#include "Projet_DMX.h"



QSqlDatabase connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.64.50");
    db.setPort(3306);
    db.setDatabaseName("Projet_BTS");
    db.setUserName("root");
    db.setPassword("GigaMDP25!");

    return db;
};

QList<Channel*> simulateChannels() {
    QList<Channel*> list;

    QStringList noms = { "ShutterStrobe", "Red", "Green", "Blue", "White", "Intensity" };
    for (int i = 0; i < noms.size(); ++i) {
        Channel* c = new Channel();
        c->name = noms[i];
        c->channelnumber = i + 1;
        c->id = i + 1;
        list.append(c);
    }

    return list;
}


Equipment* simulateEquipment() {
    Equipment* e = new Equipment();
    e->name = "Saber";
    e->id = 1;
    e->channels = simulateChannels();
    return e;
}

// Simule une scène
Scene* simulateScene() {
    Scene* s = new Scene();
    s->id = 1;
    s->Name = "TestScene";
    s->BackgroundColor = "#ff0800";
    s->TextColor = "#ffffff";
    return s;
}

// Simule une configuration
ConfigurationTrame* simulateConfigurationTrame() {
    return new ConfigurationTrame(simulateEquipment(), 1);
}

QList<ChannelValue*> simulateChannelValues(Equipment* eq) {
    QList<ChannelValue*> values;
    for (Channel* ch : eq->channels) {
        ChannelValue* val = new ChannelValue();
        val->Channel = ch;

        if (ch->name == "Red") val->value = 255;
        else if (ch->name == "Intensity") val->value = 255;
        else val->value = 0;

        values.append(val);
    }
    return values;
}

int main(int argc, char* argv[]) {

    QApplication app(argc, argv); // obligatoire pour les interfaces graphiques

    Projet_DMX window;
    window.show();  // indispensable pour afficher la fenêtre

    return app.exec();
}

    //Partie simulation

    /*QCoreApplication a(argc, argv);
    QSqlDatabase db = connectToDatabase();

    Equipment* eq = simulateEquipment();
    QList<ChannelValue*> chValues = simulateChannelValues(eq);

    qDebug() << "Équipement simulé :" << eq->name;
    for (Channel* ch : eq->channels) {
        qDebug() << "Canal" << ch->channelnumber << ":" << ch->name;
    }

    TrameManager* tm = new TrameManager(nullptr);
    qDebug() << "Scenes JSON simuler :" << tm->getScenesAsJSONString();

    // Construction de la trame DMX
    std::array<unsigned char, 512> trameDMX = {};
    for (ChannelValue* val : chValues) {
        int index = val->Channel->channelnumber - 1;
        trameDMX[index] = static_cast<unsigned char>(val->value);
    }

    // Affichage des 6 premiers canaux
    qDebug() << "Trame DMX simulée (hex) :";
    for (int i = 0; i < 6; ++i) {
        qDebug() << "Canal"
            << QString("%1").arg(i + 1, 3)
            << ": 0x"
            << QString("%1").arg(static_cast<int>(trameDMX[i]), 2, 16, QLatin1Char('0')).toUpper();
    }

    return 0;
}*/
