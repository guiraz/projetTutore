#ifndef DB_H
#define DB_H
#include <QApplication>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <iostream>
#include <QSqlError>

class Db
{
public:
    Db();
    QSqlError lastError();
    void closeDB();
private:
    QSqlDatabase * _db;

    void createTables();
};

#endif // DB_H
