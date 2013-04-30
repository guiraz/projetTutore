#ifndef MODEL_H
#define MODEL_H
#include <QStringList>
#include <QVector>

class Model
{
public:
    Model();
    virtual ~Model();
    virtual void setModel() = 0;

    //Connection******************************
    virtual QStringList getUsers();
    virtual QString getUserAt(const int & pos);
    virtual int getUsersSize();

    //NewUser
    virtual void addUser(QString name);

    //Stat
    virtual QStringList getExos();
    virtual QVector<int> getNbTentatives();
    virtual QVector<int> getMoyennes();

    //MenuExercices
    virtual void next();
    virtual void prev();
    virtual QString firstExo();
    virtual QString secondExo();

    //Exercices
    virtual QString getExo();
    virtual QString getDesc();
    virtual void nextPage();
    virtual void answer(int);
};

#endif // MODEL_H
