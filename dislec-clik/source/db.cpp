#include "db.h"

Db::Db()
{
    QString path(qApp->applicationDirPath());
    path.append(QDir::separator()).append("db").append(QDir::separator()).append("dislekclik.sqlite");
    path = QDir::toNativeSeparators(path);

    QString type = QString("QSQLITE");
    std::cout<<path.toStdString()<<std::endl;
    std::cout<<type.toStdString()<<std::endl;

    _db = new QSqlDatabase();

    if(QFile::exists(path)) //if db already exists
    {
        _db->addDatabase(type); //launch it
        _db->setDatabaseName(path);
        _db->open();
    }
    else
    {
        _db->addDatabase(type); //vreate and launch it
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
