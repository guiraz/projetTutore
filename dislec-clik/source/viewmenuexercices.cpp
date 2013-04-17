#include "viewmenuexercices.h"
#include "controller.h"

ViewMenuExercices::ViewMenuExercices(Controller * parent) : View(), _parent(parent)
{
}

ViewMenuExercices::~ViewMenuExercices()
{
    _parent = NULL;
    delete _parent;
}

void ViewMenuExercices::setView()
{
    QIcon exo1I, exo2I, prevI, nextI, retourI, exitI;
    QString exo1T("Exercice 1"), exo2T("Exercice 2"), prevT("Précèdent"), nextT("Suivant"), retourT("Retour"), exitT("Quitter");


    exo1I.addPixmap(QPixmap("images/process.png"));
    exo2I.addPixmap(QPixmap("images/process.png"));
    prevI.addPixmap(QPixmap("images/rewind.png"));
    nextI.addPixmap(QPixmap("images/forward.png"));
    retourI.addPixmap(QPixmap("images/retour.jpg"));
    exitI.addPixmap(QPixmap("images/exit.png"));

    int x = (_parent->size().width()-15)/2;
    int y = (_parent->size().height()-20)/3;


    _buttonExo1.setParent(_parent);
    _buttonExo1.setGeometry(5, 5, x, y);
    _buttonExo1.setIcon(exo1I);
    _buttonExo1.setIconSize(QSize(200,200));
    _buttonExo1.setText(exo1T);
    _buttonExo1.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonExo1.setFont(QFont("Times New Roman", 24));
    _buttonExo1.setStyleSheet("background-color : #92C8FF;");
    _buttonExo1.setVisible(true);
    //QObject::connect(&_buttonExo1, SIGNAL(clicked()), _parent, SLOT(menuExercices()));

    _buttonExo2.setParent(_parent);
    _buttonExo2.setGeometry(x+10, 5, x, y);
    _buttonExo2.setIcon(exo2I);
    _buttonExo2.setIconSize(QSize(200,200));
    _buttonExo2.setText(exo2T);
    _buttonExo2.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonExo2.setFont(QFont("Times New Roman", 24));
    _buttonExo2.setStyleSheet("background-color : #92C8FF;");
    _buttonExo2.setVisible(true);
    //QObject::connect(&_buttonExo2, SIGNAL(clicked()), _parent, SLOT(menuStatistiques()));

    _buttonPrev.setParent(_parent);
    _buttonPrev.setGeometry(5, y+10, x, y);
    _buttonPrev.setIcon(prevI);
    _buttonPrev.setIconSize(QSize(200,200));
    _buttonPrev.setText(prevT);
    _buttonPrev.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonPrev.setFont(QFont("Times New Roman", 24));
    _buttonPrev.setStyleSheet("background-color : #92C8FF;");
    _buttonPrev.setVisible(true);
    //QObject::connect(&_buttonPrev, SIGNAL(clicked()), _parent, SLOT(quit()));

    _buttonNext.setParent(_parent);
    _buttonNext.setGeometry(x+10, y+10, x, y);
    _buttonNext.setIcon(nextI);
    _buttonNext.setIconSize(QSize(200,200));
    _buttonNext.setText(nextT);
    _buttonNext.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonNext.setFont(QFont("Times New Roman", 24));
    _buttonNext.setStyleSheet("background-color : #92C8FF;");
    _buttonNext.setVisible(true);
    //QObject::connect(&_buttonNext, SIGNAL(clicked()), _parent, SLOT(retourConnection()));

    _buttonReturn.setParent(_parent);
    _buttonReturn.setGeometry(5, (2*y)+15, x, y);
    _buttonReturn.setIcon(retourI);
    _buttonReturn.setIconSize(QSize(200,200));
    _buttonReturn.setText(retourT);
    _buttonReturn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonReturn.setFont(QFont("Times New Roman", 24));
    _buttonReturn.setStyleSheet("background-color : #92C8FF;");
    _buttonReturn.setVisible(true);
    QObject::connect(&_buttonReturn, SIGNAL(clicked()), _parent, SLOT(menu()));

    _buttonQuit.setParent(_parent);
    _buttonQuit.setGeometry(x+10, (2*y)+15, x, y);
    _buttonQuit.setIcon(exitI);
    _buttonQuit.setIconSize(QSize(200,200));
    _buttonQuit.setText(exitT);
    _buttonQuit.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonQuit.setFont(QFont("Times New Roman", 24));
    _buttonQuit.setStyleSheet("background-color : #92C8FF;");
    _buttonQuit.setVisible(true);
    QObject::connect(&_buttonQuit, SIGNAL(clicked()), _parent, SLOT(quit()));
}
