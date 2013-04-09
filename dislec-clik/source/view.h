#ifndef VIEW_H
#define VIEW_H
#include <QWidget>

class View
{
public:
    View(QWidget * parent);
    virtual ~View();
    virtual void setView() = 0;

protected:
    QWidget * _parent;
};

#endif // VIEW_H
