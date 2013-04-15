#include "modelconnection.h"
#include "controller.h"

ModelConnection::ModelConnection(Controller * parent, Db * db) : Model()
{
    _parent = parent;
    _db = db;
    _users.clear();
}

ModelConnection::~ModelConnection()
{
    _parent = NULL;
    delete _parent;

    _db = NULL;
    delete _db;
}

QStringList ModelConnection::getUsers()
{
    return _users;
}

QString ModelConnection::getUserAt(const int & pos)
{
    return _users.at(pos);
}

int ModelConnection::getUsersSize()
{
    return _users.size();
}

void ModelConnection::setModel()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM USERS;");
    query.exec();

    if (query.first())
    {
        do
        {
            _users.append(query.value(0).toString());
        }while(query.next());
    }
    query.clear();
}
