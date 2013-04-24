#ifndef MODELMENUEXERCICES_H
#define MODELMENUEXERCICES_H
#include <QSqlQuery>

#include "model.h"
#include "db.h"

class Controller;

class ModelMenuExercices : public Model
{
public:
    ModelMenuExercices(Db * db, Controller * parent);
    ~ModelMenuExercices();
    void setModel();
    void next();
    void prev();
    QString firstExo();
    QString secondExo();

private :
    Db * _db;
    Controller * _parent;
    int _firstExo, _secondExo;
    QVector<QString> _exercices;
};

#endif // MODELMENUEXERCICES_H
