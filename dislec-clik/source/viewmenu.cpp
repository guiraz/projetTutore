#include "viewmenu.h"
#include "controller.h"

ViewMenu::ViewMenu(Controller * parent) : View(), _parent(parent)
{
}

void ViewMenu::setView()
{
    QLabel goI, retourI, statI, exitI;
    QLabel goT("Exercices"), retourT("Retour"), statT("Statistiques"), exitT("Quitter");

    goI.setPixmap(QPixmap("images/go.gif"));
    retourI.setPixmap(QPixmap("images/retour.jpg"));
    statI.setPixmap(QPixmap("images/stat.jpg"));
    exitI.setPixmap(QPixmap("images/exit.png"));

    QVBoxLayout * v1, * v2, * v3, * v4;
    v1 = new QVBoxLayout;
    v1->addWidget(&goI);
    v1->addWidget(&goT);

    v2 = new QVBoxLayout;
    v2->addWidget(&statI);
    v2->addWidget(&statT);

    v3 = new QVBoxLayout;
    v3->addWidget(&exitI);
    v3->addWidget(&exitT);

    v4 = new QVBoxLayout;
    v4->addWidget(&retourI);
    v4->addWidget(&retourT);


    _buttonExercices.setParent(_parent);
    _buttonExercices.setGeometry(5, 5, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonExercices.setLayout(v1);
    _buttonExercices.setVisible(true);

    _buttonStat.setParent(_parent);
    _buttonStat.setGeometry((_parent->size().width()/2) + 3, 5, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonStat.setLayout(v2);
    _buttonStat.setVisible(true);

    _buttonQuit.setParent(_parent);
    _buttonQuit.setGeometry((_parent->size().width()/2) + 3, (_parent->size().height()/2) + 3, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonQuit.setLayout(v3);
    _buttonQuit.setVisible(true);

    _buttonReturn.setParent(_parent);
    _buttonReturn.setGeometry(5, (_parent->size().height()/2) + 3, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonReturn.setLayout(v4);
    _buttonReturn.setVisible(true);
}
