#pragma once
#include "Interface_CUD.h"
#include <QtSql/qsqldatabase.h>
#include "Channel.h"

class ChannelValue : public Interface_CUD, Channel
{
public:
	int value;
	Channel* Channel;

	bool create(QSqlDatabase* db) override;
	bool update(QSqlDatabase* db) override;
	bool deletee(QSqlDatabase* db) override; //ajout d'un "e" car le mot delete ne passe pas
};