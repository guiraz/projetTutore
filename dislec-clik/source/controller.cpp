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

    this->setPalette(QPalette(QColor(192,192,255)));
    _v = new ViewConnection(this);
    _v->setView();

    _m = new ModelConnection(this);
    _m->setModel();
}

Controller::~Controller()
{
    removeView();
    removeModel();
}

void Controller::setUser()
{
    /*QStringList users(_m->getUsers());

    for(int i=0; i<users.size(); i++)
        _v->setComboBoxUser(users.at(i));*/
}

void Controller::removeView()
{
    delete _v;
}

void Controller::removeModel()
{
    delete _m;
}

void Controller::quit()
{
    if(QMessageBox::warning(NULL, "Fermeture du programme", "Etes vous sure de vouloir arrêter le programme?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        this->close();
}

void Controller::newUser()
{
}

void Controller::connect()
{
}
