#pragma once
#include "Interface_CUD.h"
#include <qstring.h>


class Scene : public Interface_CUD
{
public:
	QString Name;
	int id;
	QString BackgroundColor;
	QString TextColor;

	bool create(QSqlDatabase* db) override;
	bool update(QSqlDatabase* db) override;
	bool deletee(QSqlDatabase* db) override; //ajout d'un "e" car le mot delete ne passe pas
	                                                                                                                                                                                                                                                                                                        

};