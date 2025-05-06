#include <QCoreApplication>
#include <QDebug>
#include "Channel.h"
#include "channelvalues.h"
#include "configurationtrame.h"
#include "DMX.h"
#include "Equipment.h"
#include "Scene.h"
#include "TrameManager.h"

// Simule la création d'un channel
Channel* simulateChannel() {
    Channel* c = new Channel();
    c->name = "Red";
    c->channelnumber = 2;
    c->id = 42;
    c->CurrentValue = 255;
    return c;
}

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
db.setHostName("192.168.64.50");


// Simule la création d'un Equipment
Equipment* simulateEquipment() {
    Equipment* e = new Equipment();
    e->name = "TestProjector";
    e->id = 1;
    e->channels.append(simulateChannel());
    return e;
}

// Simule une scène
Scene* simulateScene() {
    Scene* s = new Scene();
    s->id = 1;
    s->Name = "TestScene";
    s->BackgroundColor = "#ff0000";
    s->TextColor = "#ffffff";
    return s;
}

// Simule une configuration
ConfigurationTrame* simulateConfigurationTrame() {
    return new ConfigurationTrame(simulateEquipment(), 1);
}

// Simule une valeur de channel
ChannelValue* simulateChannelValue() {
    ChannelValue* val = new ChannelValue();
    val->value = 128;
    val->Channel = simulateChannel();
    return val;
}

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    Channel* ch = simulateChannel();
    qDebug() << "Channel simulé :" << ch->name << ch->CurrentValue;

    ChannelValue* chv = simulateChannelValue();
    qDebug() << "ChannelValue simulée :" << chv->value;

    Equipment* eq = simulateEquipment();
    qDebug() << "Equipment simulé :" << eq->name;

    ConfigurationTrame* ct = simulateConfigurationTrame();
    qDebug() << "Configuration valide ?" << ct->isValid();

    Scene* sc = simulateScene();
    qDebug() << "Scène simulée :" << sc->Name << sc->BackgroundColor;

    TrameManager* tm = new TrameManager(nullptr);
    qDebug() << "Scènes JSON simulées :" << tm->getScenesAsJSONString();

    return 0;
}
