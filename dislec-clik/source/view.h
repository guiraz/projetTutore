#ifndef VIEW_H
#define VIEW_H
#include <QWidget>

class Controller;

class View
{
public:
    View();
    virtual ~View();
    virtual void setView() = 0;
};

#endif // VIEW_H
