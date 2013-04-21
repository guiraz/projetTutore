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

int Model::getNbExo()
{
    return 0;
}

QVector<int> Model::getNbTentatives()
{
    QVector<int> r;
    return r;
}

QVector<int> Model::getMoyennes()
{
    QVector<int> r;
    return r;
}
