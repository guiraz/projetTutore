#include "view.h"

View::View(QWidget * parent) : _parent(parent)
{
}

View::~View()
{
    _parent = NULL;
    delete _parent;
}
