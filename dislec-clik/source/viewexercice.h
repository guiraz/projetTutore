#ifndef VIEWEXERCICE_H
#define VIEWEXERCICE_H
#include <QPushButton>
#include <QSignalMapper>
#include <QLabel>

#include "view.h"

class Controller;

class ViewExercice : public View
{
public:
    ViewExercice(Controller * parent);
    ~ViewExercice();
    void setView();
    void setButtonExo(QStringList list);
    void setMarkPage(QString mark);

private:
    Controller *_parent;
    QPushButton _buttonProp1, _buttonProp2, _buttonProp3, _buttonProp4;
    QSignalMapper * _mapper;
    QLabel _label1, _label2, _label3;
};

#endif // VIEWEXERCICE_H
