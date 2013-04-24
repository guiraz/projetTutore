#include "modelmenuexercices.h"
#include "controller.h"

ModelMenuExercices::ModelMenuExercices(Db * db, Controller * parent)
   : Model(), _db(db), _parent(parent)
{
}

ModelMenuExercices::~ModelMenuExercices()
{
    _parent = NULL;
    delete _parent;
    _db = NULL;
    delete _db;
}

void ModelMenuExercices::setModel()
{
    QSqlQuery query;
    query.exec("SELECT NAME FROM EXERCICES;");
    if (query.first())
    {
        do
        {
            _exercices.append(query.value(0).toString());
        }while(query.next());
    }

    if(_exercices.size()<=0)
    {
        _firstExo = -1;
        _secondExo = -1;
    }
    else
    {
        if(_exercices.size()==1)
        {
            _firstExo = _secondExo = 0;
        }
        else
        {
            _firstExo = 0;
            _secondExo = 1;
        }
    }
}

void ModelMenuExercices::next()
{
    if(_exercices.size()>0)
    {
        if(_exercices.size()==1)
        {
            _firstExo = _secondExo = 0;
        }
        else
        {
            _firstExo = _secondExo;
            _secondExo = (_secondExo + 1) % _exercices.size();
        }
    }
}

void ModelMenuExercices::prev()
{
    if(_exercices.size()>0)
    {
        if(_exercices.size()==1)
        {
            _firstExo = _secondExo = 0;
        }
        else
        {
            _secondExo = _firstExo;
            if(_firstExo == 0)
                _firstExo = _exercices.size()-1;
            else
                _firstExo = _firstExo-1;
        }
    }
}

QString ModelMenuExercices::firstExo()
{
    if(_exercices.size()>0)
        return _exercices[_firstExo];
    else
        return "";
}

QString ModelMenuExercices::secondExo()
{
    if(_exercices.size()>0)
        return _exercices[_secondExo];
    else
        return "";
}
