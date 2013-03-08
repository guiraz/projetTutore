#include "db.h"

Db::Db()
{
    if(QFile::exists("db.db")) //if db already exists
    {
        _db.addDatabase("QSQLITE", "db.db"); //launch it
    }
    else //if not, create it
    {
    }
}
