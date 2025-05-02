#pragma once
#include "Interface_CUD.h"
#include <QtSql/qsqldatabase.h>

class channelvalue : public Interface_CUD
{
public:
	int value;

	bool create(QSqlDatabase* db) override;
	bool update(QSqlDatabase* db) override;
	bool deletee(QSqlDatabase* db) override; //ajout d'un "e" car le mot delete ne passe pas
};