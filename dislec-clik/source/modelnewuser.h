#ifndef MODELNEWUSER_H
#define MODELNEWUSER_H
#include <QSqlQuery>

#include "db.h"
#include "model.h"

class Controller;

class ModelNewUser : public Model
{
public:
    ModelNewUser(Controller * parent, Db * db);
    ~ModelNewUser();
    void setModel();

    void addUser(QString name);

private :
    Controller * _parent;
    Db * _db;
};

#endif // MODELNEWUSER_H
