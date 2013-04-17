#ifndef VIEWMENU_H
#define VIEWMENU_H
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QLayout>

#include "view.h"

class Controller;

class ViewMenu : public View
{
public:
    ViewMenu(Controller * parent);
    void setView();

private :
    Controller * _parent;
    QPushButton _buttonQuit, _buttonReturn, _buttonExercices, _buttonStat;
};

#endif // VIEWMENU_H
