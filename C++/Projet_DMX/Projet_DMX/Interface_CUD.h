#pragma once

#ifndef Interface_CUD_H
#define Interface_CUD_H

#include <QtSql/qsqldatabase.h>

class Interface_CUD

{
public:
	virtual ~Interface_CUD() {}

	virtual bool create(QSqlDatabase* db) = 0;
	virtual bool update(QSqlDatabase* db) = 0;
	virtual bool deletee(QSqlDatabase* db) = 0; //ajout d'un "e" car le mot delete ne passe pas

};

#endif