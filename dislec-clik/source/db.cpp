#include "db.h"

Db::Db()
{
    QString path(qApp->applicationDirPath());
    path.append(QDir::separator()).append("db").append(QDir::separator()).append("dislekclik.sqlite");
    path = QDir::toNativeSeparators(path);

    QString pathDir(qApp->applicationDirPath());
    pathDir.append(QDir::separator()).append("db").append(QDir::separator());
    pathDir = QDir::toNativeSeparators(pathDir);

    QString type = QString("QSQLITE");
    _db = new QSqlDatabase(QSqlDatabase::addDatabase(type));

    if(QFile::exists(path)) //if db already exists
    {
        _db->setDatabaseName(path);
        _db->open();
    }
    else
    {
        QDir d;
        d.mkpath(pathDir);
        _db->setDatabaseName(path);
        _db->open();
        createDB();
    }
}

QSqlError Db::lastError()
{
    return _db->lastError();
}

void Db::closeDB()
{
    _db->close();
}

QSqlDatabase * Db::getDBRef()
{
    return _db;
}

void Db::createDB()
{
    QSqlQuery query;
    query.exec("CREATE TABLE USERS (NAME VARCHAR(15) UNIQUE NOT NULL, PRIMARY KEY (NAME));");
}
