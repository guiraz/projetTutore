#ifndef MODELCONNECTION_H
#define MODELCONNECTION_H
#include "db.h"
#include "model.h"

class Controller;

class ModelConnection : public Model
{
public:
    ModelConnection(Controller * parent);
    ~ModelConnection();
    virtual void setModel();
    QStringList getUsers();

private:
    Db _db;
    Controller * _parent;
    QStringList _users;
};

#endif // MODELCONNECTION_H
