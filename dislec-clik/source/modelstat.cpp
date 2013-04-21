#include "modelstat.h"
#include "controller.h"

ModelStat::ModelStat(Controller * parent, Db * db) : Model(), _parent(parent), _db(db)
{
}

ModelStat::~ModelStat()
{
    _parent = NULL;
    _db = NULL;

    delete _parent;
    delete _db;
}

void ModelStat::setModel()
{
    _user = _parent->getUser();
    QSqlQuery query;
    query.exec("SELECT COUNT(ID) FROM EXERCICES;");
    query.first();
    _nbExo = query.value(0).toInt();

    for(int i=0; i<_nbExo; i++)
    {
        query.exec("SELECT COUNT(ID) FROM SUIVIS WHERE USER_NAME='" + _user +"' AND EXERCICE_ID='" + QString::number(i+1) + "';");
        if(query.first())
            _nbTentatives.append(query.value(0).toInt());
        else
            _nbTentatives.append(0);
    }

    for(int i=0; i<_nbExo; i++)
    {
        query.exec("SELECT SUM(NOTE) FROM SUIVIS WHERE USER_NAME='" + _user +"' AND EXERCICE_ID='" + QString::number(i+1) + "';");
        if(query.first())
        {
            _moyennes.append(query.value(0).toInt());
            _moyennes[i]/=_nbTentatives[i];
        }
        else
            _moyennes.append(0);
    }
}

int ModelStat::getNbExo()
{
    return _nbExo;
}

QVector<int> ModelStat::getNbTentatives()
{
    return _nbTentatives;
}

QVector<int> ModelStat::getMoyennes()
{
    return _moyennes;
}
