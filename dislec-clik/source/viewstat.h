#ifndef VIEWSTAT_H
#define VIEWSTAT_H
#include <QToolButton>
#include <QGridLayout>
#include <QLabel>
#include <QVector>

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
    QWidget _widgetStat;
    QGridLayout _layout;
    QLabel * _labels;
};

#endif // VIEWSTAT_H
