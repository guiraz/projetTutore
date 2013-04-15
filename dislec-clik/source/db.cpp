#include "db.h"

Db::Db()
{
    QString path(qApp->applicationDirPath());
    path.append(QDir::separator()).append("db").append(QDir::separator()).append("dislekclik.sqlite");
    path = QDir::toNativeSeparators(path);

    QString type = QString("QSQLITE");
    _db = new QSqlDatabase(QSqlDatabase::addDatabase(type));

    if(QFile::exists(path)) //if db already exists
    {
        _db->setDatabaseName(path);
        _db->open();
        std::cout<<lastError().text().toStdString()<<std::endl;
    }
    else
    {
        _db->setDatabaseName(path);
        _db->open();
        createTables();
    }
}

QSqlError Db::lastError()
{
    return _db->lastError();
}

void Db::createTables()
{
    QSqlQuery query;
    query.prepare("CREATE TABLE USERS (NAME VARCHAR(15) PRIMARY KEY);");
    query.exec();
}
