#ifndef MODEL_H
#define MODEL_H
#include <QStringList>

class Model
{
public:
    Model();
    virtual ~Model();
    virtual void setModel() = 0;
    virtual QStringList getUsers();
};

#endif // MODEL_H
