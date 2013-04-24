#include "modelnewuser.h"
#include "controller.h"

ModelNewUser::ModelNewUser(Controller * parent, Db * db) : Model()
{
    _parent = parent;
    _db = db;
}

ModelNewUser::~ModelNewUser()
{
    _parent = NULL;
    delete _parent;
    _db = NULL;
    delete _db;
}

void ModelNewUser::setModel()
{
}

void ModelNewUser::addUser(QString name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO USERS (NAME) VALUES (\"" + name + "\");");
    query.exec();
    query.clear();
}
