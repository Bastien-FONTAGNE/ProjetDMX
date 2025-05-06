#pragma once

#include "DMX.h"
#include "ConfigurationTrame.h"
#include "Scene.h"
#include <QList>
#include <QMap>
#include <QTimer>
#include <QtWebSockets/qwebsocket.h>
#include <QtWebSockets/qwebsocketserver.h>
#include <QtSql/QSqlDatabase>

class TrameManager : public QObject {
    Q_OBJECT

private:
    QList<ConfigurationTrame*> config;
    std::array<unsigned char, 512> frame;
    QTimer* timer;
    DMX* dmx;
    QMap<int, Scene*> scenes;
    QWebSocketServer* webSocketServer;
    QList<QWebSocket*> clients;
    QSqlDatabase* db;

public:
    TrameManager(QSqlDatabase* database, QObject* parent = nullptr);
    ~TrameManager();

    void applyScene(int id);
    void loadConfiguration();
    void sendTrame();
    QString getScenesAsJSONString();

public slots:
    void onWSClientConnected();
    void onWSClientDisconnected();
    void onWSClientReadyRead();
};
