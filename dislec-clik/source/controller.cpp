#include "controller.h"
#include "model.h"
#include "view.h"

Controller::Controller() : QWidget()
{

    QSize s = qApp->desktop()->size();
    int dW = s.width() - WIN_WIDTH;
    int dH = s.height() - WIN_HEIGHT;
    dW /= 2;
    dH /= 2;
    setGeometry(dW, dH, WIN_WIDTH, WIN_HEIGHT);
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);

    _mouse = false;

    this->setPalette(QPalette(QColor(192,192,255)));

    _m = new ModelConnection(this, &_db);
    _m->setModel();

    _v = new ViewConnection(this);
    _v->setView();
}

Controller::~Controller()
{
    delete _v;
    delete _m;
    _db.closeDB();
}

void Controller::setUser()
{
    for(int i=0; i<_m->getUsersSize(); i++)
        _v->setComboBoxUser(_m->getUserAt(i));
}

QString Controller::getUser()
{
    return _user;
}

QStringList Controller::getExos()
{
    return _m->getExos();
}

QVector<int> Controller::getTentatives()
{
    return _m->getNbTentatives();
}

QVector<int> Controller::getMoyennes()
{
    return _m->getMoyennes();
}

QString Controller::getExoName()
{
    return _m->getExo();
}

QString Controller::getExoDesc()
{
    return _m->getDesc();
}

void Controller::setUIExo(QStringList list)
{
    if(list.size()==4)
    {
        _v->setButtonExo(list);
    }
    if(list.size()==1)
    {
        _mouse = true;
        _v->setMarkPage(list.at(0));
    }
}

void Controller::menuExo()
{
    this->menuExercices();
}

void Controller::quit()
{
    if(QMessageBox::warning(NULL, "Fermeture du programme", "Etes vous sure de vouloir arrêter le programme?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        this->close();
}

void Controller::newUser()
{
    delete _v;
    delete _m;
    _m = new ModelNewUser(this, &_db);
    _m->setModel();
    _v = new ViewNewUser(this);
    _v->setView();
}

void Controller::connect()
{
    if(_m->getUsersSize() > 0)
    {
        _user = _m->getUserAt(_v->getCurrent());

        menu();
    }
}

void Controller::newUserName(QString name)
{
    if((name.size()>15) || (name.size()<1))
        _v->erreur(true);
    else
        _v->erreur(false);
}

void Controller::retourConnection()
{
    delete _m;
    _m = new ModelConnection(this, &_db);
    _m->setModel();
    delete _v;
    _v = new ViewConnection(this);
    _v->setView();
}

void Controller::addUser()
{
    if(_v->correctName())
    {
        _m->addUser(_v->getName());
    }
    retourConnection();
}

void Controller::menuExercices()
{
    delete _m;
    _m = new ModelMenuExercices(&_db, this);
    _m->setModel();
    delete _v;
    _v = new ViewMenuExercices(this);
    _v->setView();
    _v->changeTextButton(_m->firstExo(), _m->secondExo());
}

void Controller::menuStatistiques()
{
    delete _m;
    _m = new ModelStat(this, &_db);
    _m->setModel();
    delete _v;
    _v = new ViewStat(this);void setUIExo(QStringList list);
    _v->setView();
}

void Controller::menu()
{
    delete _m;
    _m = NULL;

    delete _v;
    _v = new ViewMenu(this);
    _v->setView();
}

void Controller::nextExo()
{
    _m->next();
    _v->changeTextButton(_m->firstExo(), _m->secondExo());
}

void Controller::prevExo()
{
    _m->prev();
    _v->changeTextButton(_m->firstExo(), _m->secondExo());
}

void Controller::firstExo()
{
    QString exo = _m->firstExo();
    delete _m;
    _m = new ModelExercice(exo, &_db, this);
    _m->setModel();
    delete _v;
    _v = new ViewExercice(this);
    _v->setView();

    _mouse = true;
}

void Controller::secondExo()
{
    QString exo = _m->secondExo();
    delete _m;
    _m = new ModelExercice(exo, &_db, this);
    _m->setModel();
    delete _v;
    _v = new ViewExercice(this);
    _v->setView();

    _mouse = true;
}

void Controller::propEvent(int prop)
{
    switch(prop)
    {
        case 1:
            _m->answer(0);
            break;
        case 2:
            _m->answer(1);
            break;
        case 3:
            _m->answer(2);
            break;
        case 4:
            _m->answer(3);
            break;
        default:
            break;
    }
    _m->nextPage();
}

void Controller::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    if(event->key()==Qt::Key_Escape)
        quit();
}

void Controller::mousePressEvent(QMouseEvent * event)
{
    QWidget::mousePressEvent(event);
    if(_mouse)
    {
        _mouse = false;
        _m->nextPage();
    }
}
