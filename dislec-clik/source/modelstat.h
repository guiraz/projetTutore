#ifndef MODELSTAT_H
#define MODELSTAT_H
#include <QVector>
#include <QSqlQuery>
#include <iostream>

#include "model.h"
#include "db.h"

class Controller;

class ModelStat : public Model
{
public:
    ModelStat(Controller * parent, Db * db);
    ~ModelStat();
    void setModel();

    QStringList getExos();
    QVector<int> getNbTentatives();
    QVector<int> getMoyennes();

private :
    Controller * _parent;
    Db * _db;
    QString _user;

    int _nbExo;
    QVector<int> _nbTentatives;
    QVector<int> _moyennes;

};

#endif // MODELSTAT_H
