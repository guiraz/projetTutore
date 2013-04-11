#ifndef DB_H
#define DB_H

#include <iostream>
#include <QSqlDatabase>
#include <QFile>

class Db
{
public:
    Db();
private:
    QSqlDatabase _db;
};

#endif // DB_H
