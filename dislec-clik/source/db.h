#ifndef DB_H
#define DB_H
#include <QApplication>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <iostream>
#include <QSqlError>
#include <QDebug>

class Db
{
public:
    Db();
    QSqlError lastError();
    void closeDB();
    QSqlDatabase * getDBRef();
private:
    QSqlDatabase * _db;

    void createDB();
};

#endif // DB_H
