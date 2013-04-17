#ifndef VIEWMENU_H
#define VIEWMENU_H
#include <QToolButton>
#include <QPixmap>
#include <QIcon>
#include <QLayout>

#include "view.h"

class Controller;

class ViewMenu : public View
{
public:
    ViewMenu(Controller * parent);
    ~ViewMenu();
    void setView();

private :
    Controller * _parent;
    QToolButton _buttonQuit, _buttonReturn, _buttonExercices, _buttonStat;
};

#endif // VIEWMENU_H
