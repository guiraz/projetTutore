#ifndef MODELSTAT_H
#define MODELSTAT_H

#include "model.h"
#include "db.h"

class Controller;

class ModelStat : public Model
{
public:
    ModelStat(Controller * parent, Db * db, QString * user);
    ~ModelStat();
    void setModel();

private :
    Controller * _parent;
    Db * _db;
    QString * _user;
};

#endif // MODELSTAT_H
