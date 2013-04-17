#include "viewconnection.h"
#include "controller.h"


ViewConnection::ViewConnection(Controller * parent) : View()
{
    _parent = parent;
}

ViewConnection::~ViewConnection()
{
    _parent = NULL;
    delete _parent;
}

void ViewConnection::setView()
{
    _parent->setUser();

    _labelIcon.setParent(_parent);
    _labelIcon.setPixmap(QPixmap("images/dislekclik.png"));
    _labelIcon.setAlignment(Qt::AlignCenter);
    _labelIcon.setGeometry(_parent->width()/2-250,_parent->height()/2-315,500,200);
    _labelIcon.setVisible(true);

    _label.setParent(_parent);
    _label.setText("Quel est ton prénom?");
    _label.setAlignment(Qt::AlignCenter);
    _label.setFont(QFont("Times New Roman", 24));
    _label.setGeometry(_parent->width()/2-150,_parent->height()/2-110,300,50);
    _label.setVisible(true);

    _comboBox.setParent(_parent);
    _comboBox.setGeometry(_parent->width()/2-200,_parent->height()/2-55, 400,50);
    _comboBox.setVisible(true);

    _buttonConnect.setParent(_parent);
    _buttonConnect.setText("Connecter");
    QObject::connect(&_buttonConnect, SIGNAL(clicked()),_parent,  SLOT(connect()));
    _buttonConnect.setGeometry(_parent->width()/2-75, _parent->height()/2+5, 150, 30);
    _buttonConnect.setVisible(true);

    _buttonNew.setParent(_parent);
    _buttonNew.setText("Nouvel utilisateur");
    QObject::connect(&_buttonNew, SIGNAL(clicked()),_parent,  SLOT(newUser()));
    _buttonNew.setGeometry(_parent->width()/2-75, _parent->height()/2+40, 150, 30);
    _buttonNew.setVisible(true);

    _buttonQuit.setParent(_parent);
    _buttonQuit.setText("Quitter");
    QObject::connect(&_buttonQuit, SIGNAL(clicked()),_parent,  SLOT(quit()));
    _buttonQuit.setGeometry(_parent->width()/2-75, _parent->height()/2+75, 150, 30);
    _buttonQuit.setVisible(true);
}

void ViewConnection::setComboBoxUser(const QString & user)
{
    _comboBox.addItem(user);
}

int ViewConnection::getCurrent()
{
    return _comboBox.currentIndex();
}
