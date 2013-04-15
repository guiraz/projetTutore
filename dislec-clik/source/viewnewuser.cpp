#include "viewnewuser.h"
#include "controller.h"

ViewNewUser::ViewNewUser(Controller * parent) : View()
{
    _parent = parent;
}

ViewNewUser::~ViewNewUser()
{
    _parent = NULL;
    delete _parent;
}

void ViewNewUser::setView()
{
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

    _lineEdit.setParent(_parent);
    _lineEdit.setGeometry(_parent->width()/2-200,_parent->height()/2-45, 400,30);
    QObject::connect(&_lineEdit, SIGNAL(textChanged(QString)), _parent, SLOT(newUserName(QString)));
    _lineEdit.setVisible(true);

    _buttonCreer.setParent(_parent);
    _buttonCreer.setText("Creer");
    QObject::connect(&_buttonCreer, SIGNAL(clicked()),_parent,  SLOT(connect()));
    _buttonCreer.setGeometry(_parent->width()/2-75, _parent->height()/2+5, 150, 30);
    _buttonCreer.setVisible(true);

    _buttonRetour.setParent(_parent);
    _buttonRetour.setText("Retour");
    QObject::connect(&_buttonRetour, SIGNAL(clicked()),_parent,  SLOT(retour()));
    _buttonRetour.setGeometry(_parent->width()/2-75, _parent->height()/2+40, 150, 30);
    _buttonRetour.setVisible(true);

    _labelErreur.setParent(_parent);
    _labelErreur.setText("Le nom doit comporter au minimum un caractère et au maximum quinze caractères.");
    _labelErreur.setStyleSheet("color : red;");
    _labelErreur.setGeometry(_parent->width()/2-300, _parent->height()/2+110, 600, 30);
    _labelErreur.setVisible(false);
}

void ViewNewUser::erreur(bool affiche)
{
    _labelErreur.setVisible(affiche);
}
