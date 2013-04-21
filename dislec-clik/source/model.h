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
    virtual int getNbExo();
    virtual QVector<int> getNbTentatives();
    virtual QVector<int> getMoyennes();
};

#endif // MODEL_H
