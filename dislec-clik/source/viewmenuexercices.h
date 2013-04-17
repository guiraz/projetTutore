#ifndef VIEWMENUEXERCICES_H
#define VIEWMENUEXERCICES_H
#include <QToolButton>

#include "view.h"
#include "db.h"

class Controller;

class ViewMenuExercices : public View
{
public:
    ViewMenuExercices(Controller * parent);
    ~ViewMenuExercices();
    void setView();

private:
    Controller * _parent;
    QToolButton _buttonExo1, _buttonExo2,_buttonPrev, _buttonNext, _buttonReturn, _buttonQuit;
};

#endif // VIEWMENUEXERCICES_H
