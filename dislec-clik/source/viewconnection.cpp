#include "viewconnection.h"

ViewConnection::ViewConnection(QWidget * parent) : View(parent)
{
}

ViewConnection::~ViewConnection()
{
    _parent = NULL;
    delete _parent;
}

void ViewConnection::setView()
{
    QSize s = qApp->desktop()->size();

    _label.setParent(_parent);
    _label.setText("Quel est ton prénom?");
    _label.setAlignment(Qt::AlignCenter);
    _label.setFont(QFont("Times New Roman", 24));
    _label.setGeometry(s.width()/2-150,s.height()/2-120,300,37);

    _comboBox.setParent(_parent);
    _comboBox.setGeometry(s.width()/2-75,s.height()/2-18,150,37);

    _buttonQuit.setParent(_parent);
    _buttonQuit.setText("Quitter");
    _buttonQuit.setGeometry(s.width()/2-49,s.height()/2+60,97,27);
    QObject::connect(&_buttonQuit, SIGNAL(clicked()),_parent,  SLOT(quit()));
}
