#include "modelnewuser.h"
#include "controller.h"

ModelNewUser::ModelNewUser(Controller * parent, Db * db) : Model()
{
    _parent = parent;
    _db = db;
}

ModelNewUser::~ModelNewUser()
{
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
