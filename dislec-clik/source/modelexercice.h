#ifndef MODELEXERCICE_H
#define MODELEXERCICE_H
#include <QDebug>
#include <time.h>

#include "model.h"
#include "db.h"

class Controller;

class ModelExercice : public Model
{
public:
    ModelExercice(QString exo, Db * _db, Controller * parent);
    ~ModelExercice();
    void setModel();

    QString getExo();
    QString getDesc();
    void nextPage();
    void answer(int);

private:
    QString _exo;
    QString _desc;
    Db * _db;
    Controller * _parent;

    int _currentPage;
    int _currentAnswer;
    int _correctAnswer;

    QVector<int> _listeExo;
    QStringList _listePropositions;
};

#endif // MODELEXERCICE_H
