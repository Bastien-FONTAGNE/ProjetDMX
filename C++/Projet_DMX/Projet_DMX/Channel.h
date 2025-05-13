#pragma once
#include "Interface_CUD.h"
#include <qstring.h>
#include <QtSql/qsqldatabase.h>

class Channel : public Interface_CUD {
	
public: 
	QString name;
	int channelnumber; 
	int id;
	int CurrentValue;

	bool create(QSqlDatabase* db) override;
	bool update(QSqlDatabase* db) override;
	bool deletee(QSqlDatabase* db) override; //ajout d'un "e" car le mot delete ne passe pas

};
