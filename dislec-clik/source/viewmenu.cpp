#include "viewmenu.h"
#include "controller.h"

ViewMenu::ViewMenu(Controller * parent) : View(), _parent(parent)
{
}

ViewMenu::~ViewMenu()
{
    _parent = NULL;
    delete _parent;
}

void ViewMenu::setView()
{
    QIcon goI, retourI, statI, exitI;
    QString goT("Exercices"), retourT("Retour"), statT("Statistiques"), exitT("Quitter");

    goI.addPixmap(QPixmap("images/go.gif"));
    retourI.addPixmap(QPixmap("images/retour.jpg"));
    statI.addPixmap(QPixmap("images/stat.jpg"));
    exitI.addPixmap(QPixmap("images/exit.png"));


    _buttonExercices.setParent(_parent);
    _buttonExercices.setGeometry(5, 5, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonExercices.setIcon(goI);
    _buttonExercices.setIconSize(QSize(300,300));
    _buttonExercices.setText(goT);
    _buttonExercices.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonExercices.setFont(QFont("Times New Roman", 24));
    _buttonExercices.setStyleSheet("background-color : #92C8FF;");
    _buttonExercices.setVisible(true);
    QObject::connect(&_buttonExercices, SIGNAL(clicked()), _parent, SLOT(menuExercices()));

    _buttonStat.setParent(_parent);
    _buttonStat.setGeometry((_parent->size().width()/2) + 3, 5, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonStat.setIcon(statI);
    _buttonStat.setIconSize(QSize(300,300));
    _buttonStat.setText(statT);
    _buttonStat.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonStat.setFont(QFont("Times New Roman", 24));
    _buttonStat.setStyleSheet("background-color : #92C8FF;");
    _buttonStat.setVisible(true);
    QObject::connect(&_buttonStat, SIGNAL(clicked()), _parent, SLOT(menuStatistiques()));

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
    QObject::connect(&_buttonReturn, SIGNAL(clicked()), _parent, SLOT(retourConnection()));
}
