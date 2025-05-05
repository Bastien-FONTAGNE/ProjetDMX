#pragma once
#include "Interface_CUD.h"
#include <QtSql/qsqldatabase.h>
#include "Channel.h"

class Equipment : public Interface_CUD
{
public:
	QList<Channel*> channels;
	QString name;
	int id;

	bool create(QSqlDatabase* db) override;
	bool update(QSqlDatabase* db) override;
	bool deletee(QSqlDatabase* db) override; //ajout d'un "e" car le mot delete ne passe pas
};