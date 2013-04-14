#include "modelconnection.h"
#include "controller.h"

ModelConnection::ModelConnection(Controller * parent) : Model(), _parent(parent)
{
    _users.clear();
}

ModelConnection::~ModelConnection()
{
    _parent = NULL;
    delete _parent;
}

QStringList ModelConnection::getUsers()
{
    return _users;
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
