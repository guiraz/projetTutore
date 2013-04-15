#ifndef VIEWNEWUSER_H
#define VIEWNEWUSER_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include "view.h"

class Controller;

class ViewNewUser : public View
{
public:
    ViewNewUser(Controller * parent);
    ~ViewNewUser();
    void setView();

    void erreur(bool affiche);
private:
    Controller * _parent;
    QPushButton _buttonRetour, _buttonCreer;
    QLabel _label, _labelIcon, _labelErreur;
    QLineEdit _lineEdit;
};

#endif // VIEWNEWUSER_H
