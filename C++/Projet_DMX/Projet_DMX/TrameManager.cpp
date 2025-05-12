#include "TrameManager.h"
#include <QDebug>

TrameManager::TrameManager(QSqlDatabase* database, QObject* parent)
    : QObject(parent), db(database), timer(nullptr), dmx(nullptr), webSocketServer(nullptr) {
    frame.fill(0);
}

TrameManager::~TrameManager() {}

void TrameManager::applyScene(int id) {
    qDebug() << "applyScene simulé pour id:" << id;
}

void TrameManager::loadConfiguration() {
    qDebug() << "loadConfiguration simulé";
}

void TrameManager::sendTrame() {
    if (dmx) dmx->sendTrame(frame);
}

QString TrameManager::getScenesAsJSONString() {
    return "[{\"id\":1,\"name\":\"Scène test\",\"backgroundColor\":\"#000000\",\"textColor\":\"#ffffff\"}]";
}

void TrameManager::onWSClientConnected() {
    qDebug() << "Client connecté simulé";
}

void TrameManager::onWSClientDisconnected() {
    qDebug() << "Client déconnecté simulé";
}

void TrameManager::onWSClientReadyRead() {
    qDebug() << "Réception simulée";
}