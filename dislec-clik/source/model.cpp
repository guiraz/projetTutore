#include "model.h"

Model::Model()
{
}

Model::~Model()
{
}


QStringList Model::getUsers()
{
    return QStringList();
}

QString Model::getUserAt(const int & pos)
{
    QString retour(QString::number(pos));
    return retour;
}

int Model::getUsersSize()
{
    return 0;
}

void Model::addUser(QString name)
{
}
