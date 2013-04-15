#ifndef MODEL_H
#define MODEL_H
#include <QStringList>

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
};

#endif // MODEL_H
