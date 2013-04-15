#ifndef MODELCONNECTION_H
#define MODELCONNECTION_H
#include "db.h"
#include "model.h"

class Controller;

class ModelConnection : public Model
{
public:
    ModelConnection(Controller * parent, Db * db);
    ~ModelConnection();
    virtual void setModel();
    QStringList getUsers();
    QString getUserAt(const int & pos);
    int getUsersSize();

private:
    Db * _db;
    Controller * _parent;
    QStringList _users;
};

#endif // MODELCONNECTION_H
