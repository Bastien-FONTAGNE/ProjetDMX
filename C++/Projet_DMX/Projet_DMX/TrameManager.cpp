#include "TrameManager.h"
#include <QDebug>

TrameManager::TrameManager(QSqlDatabase* database, QObject* parent)
    : QObject(parent), db(database), timer(nullptr), dmx(nullptr), webSocketServer(nullptr) {
    frame.fill(0);
}

TrameManager::~TrameManager() {}

void TrameManager::applyScene(int id) {
    qDebug() << "applyScene simul� pour id:" << id;
}

void TrameManager::loadConfiguration() {
    qDebug() << "loadConfiguration simul�";
}

void TrameManager::sendTrame() {
    if (dmx) dmx->sendTrame(frame);
}

QString TrameManager::getScenesAsJSONString() {
    return "[{\"id\":1,\"name\":\"Sc�ne test\",\"backgroundColor\":\"#000000\",\"textColor\":\"#ffffff\"}]";
}

void TrameManager::onWSClientConnected() {
    qDebug() << "Client connect� simul�";
}

void TrameManager::onWSClientDisconnected() {
    qDebug() << "Client d�connect� simul�";
}

void TrameManager::onWSClientReadyRead() {
    qDebug() << "R�ception simul�e";
}