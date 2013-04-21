#include "viewstat.h"
#include "controller.h"

ViewStat::ViewStat(Controller * parent) : View(), _parent(parent)
{
}

ViewStat::~ViewStat()
{
    _parent = NULL;
    delete _parent;
}

void ViewStat::setView()
{
    QIcon retourI, exitI;
    QString retourT("Retour"), exitT("Quitter");

    retourI.addPixmap(QPixmap("images/retour.png"));
    exitI.addPixmap(QPixmap("images/exit.png"));

    _buttonQuit.setParent(_parent);
    _buttonQuit.setGeometry((_parent->size().width()/2) + 3, (_parent->size().height()/2) + 3, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonQuit.setIcon(exitI);
    _buttonQuit.setIconSize(QSize(250,250));
    _buttonQuit.setText(exitT);
    _buttonQuit.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonQuit.setFont(QFont("Times New Roman", 24));
    _buttonQuit.setStyleSheet("background-color : #92C8FF;");
    _buttonQuit.setVisible(true);
    QObject::connect(&_buttonQuit, SIGNAL(clicked()), _parent, SLOT(quit()));

    _buttonReturn.setParent(_parent);
    _buttonReturn.setGeometry(5, (_parent->size().height()/2) + 3, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonReturn.setIcon(retourI);
    _buttonReturn.setIconSize(QSize(300,300));
    _buttonReturn.setText(retourT);
    _buttonReturn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonReturn.setFont(QFont("Times New Roman", 24));
    _buttonReturn.setStyleSheet("background-color : #92C8FF;");
    _buttonReturn.setVisible(true);
    QObject::connect(&_buttonReturn, SIGNAL(clicked()), _parent, SLOT(menu()));
}
