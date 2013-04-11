#include "db.h"

Db::Db()
{
    if(QFile::exists("db.db")) //if db already exists
    {
        _db.addDatabase("QSQLITE", "db.db"); //launch it
    }
    else
    {
        std::cerr<<"Could not open database."<<std::endl;
        exit(-1);
    }
}
