#ifndef VIEWSTAT_H
#define VIEWSTAT_H
#include <QToolButton>

#include "view.h"

class Controller;

class ViewStat : public View
{
public:
    ViewStat(Controller * parent);
    ~ViewStat();
    void setView();

private :
    Controller * _parent;
    QToolButton _buttonReturn, _buttonQuit;
};

#endif // VIEWSTAT_H
