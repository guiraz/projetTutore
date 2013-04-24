#include "modelexercice.h"
#include "controller.h"

ModelExercice::ModelExercice(QString exo, Db * db, Controller * parent)
    : Model(), _exo(exo), _db(db), _parent(parent)
{
}

ModelExercice::~ModelExercice()
{
    _parent = NULL;
    delete _parent;
    _db = NULL;
    delete _db;

    _listeExo.clear();
    _listePropositions.clear();
}

void ModelExercice::setModel()
{
    srand (time(NULL));

    QSqlQuery query;
    query.exec("SELECT DESC FROM EXERCICES WHERE NAME='"+_exo+"';");
    query.first();
    _desc = query.value(0).toString();

    query.clear();

    while(_listeExo.size()<10)
    {
        int r = rand()%50;
        if(!_listeExo.contains(r))
            _listeExo.append(r);
    }

    query.exec("SELECT PROP1, PROP2, PROP3, PROP4 FROM PROPOSITIONS, EXERCICES WHERE EXERCICES.ID=PROPOSITIONS.EXERCICE_ID AND NAME='"+_exo+"';");

    if(query.first())
    {
        do
        {
            _listePropositions.append(query.value(0).toString());
            _listePropositions.append(query.value(1).toString());
            _listePropositions.append(query.value(2).toString());
            _listePropositions.append(query.value(3).toString());
        }while(query.next());
    }

    query.clear();

    _currentPage = -1;
}
