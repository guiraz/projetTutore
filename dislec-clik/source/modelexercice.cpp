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
    _correctAnswer = 0;
}

QString ModelExercice::getExo()
{
    return _exo;
}

QString ModelExercice::getDesc()
{
    return _desc;
}

void ModelExercice::nextPage()
{
    _currentPage++;
    if(_currentPage<10)
    {
        QStringList l;
        int i=0;
        QVector<bool> affected;
        affected.fill(false,4);
        while(i<4)
        {
            switch(rand()%4)
            {
                case 0:
                    if(!affected[0])
                    {
                        l<<_listePropositions[_listeExo[_currentPage]*4];
                        affected[0]=true;
                        _currentAnswer = i;
                        i++;
                    }
                    break;
                case 1:
                    if(!affected[1])
                    {
                        l<<_listePropositions[_listeExo[_currentPage]*4+1];
                        affected[1]=true;
                        i++;
                    }
                    break;
                case 2:
                    if(!affected[2])
                    {
                        l<<_listePropositions[_listeExo[_currentPage]*4+2];
                        affected[2]=true;
                        i++;
                    }
                    break;
                case 3:
                    if(!affected[3])
                    {
                        l<<_listePropositions[_listeExo[_currentPage]*4+3];
                        affected[3]=true;
                        i++;
                    }
                    break;
            }
        }
        _parent->setUIExo(l);
    }
    if(_currentPage==10)
    {
        QSqlQuery query;
        query.exec("SELECT ID FROM EXERCICES WHERE NAME='"+_exo+"';");
        query.first();
        int idExo = query.value(0).toInt();
        query.clear();
        query.exec("SELECT MAX(ID) FROM SUIVIS;");
        int idSuivi;
        if(query.first())
            idSuivi = query.value(0).toInt()+1;
        else
            idSuivi = 0;
        query.clear();
        query.exec("INSERT INTO SUIVIS VALUES ('"+QString::number(idSuivi)+"','"+_parent->getUser()+"','"+QString::number(idExo)+"','"+QString::number(_correctAnswer)+"');");
        query.clear();

        QStringList l;
        l<<QString::number(_correctAnswer);
        _parent->setUIExo(l);
    }
    if(_currentPage>10)
        _parent->menuExo();
}

void ModelExercice::answer(int answer)
{
    if(_currentAnswer==answer)
        _correctAnswer++;
}

