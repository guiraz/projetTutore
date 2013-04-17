#include "modelstat.h"
#include "controller.h"

ModelStat::ModelStat(Controller * parent, Db * db, QString * user) : Model(), _parent(parent), _db(db), _user(user)
{
}

ModelStat::~ModelStat()
{
    _parent = NULL;
    _db = NULL;
    _user = NULL;

    delete _parent;
    delete _db;
    delete _user;
}

void ModelStat::setModel()
{
}
