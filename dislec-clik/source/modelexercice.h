#ifndef MODELEXERCICE_H
#define MODELEXERCICE_H
#include <QDebug>

#include "model.h"
#include "db.h"

class Controller;

class ModelExercice : public Model
{
public:
    ModelExercice(QString exo, Db * _db, Controller * parent);
    ~ModelExercice();
    void setModel();

private:
    QString _exo;
    QString _desc;
    Db * _db;
    Controller * _parent;

    int _currentPage;

    QVector<int> _listeExo;
    QStringList _listePropositions;
};

#endif // MODELEXERCICE_H
