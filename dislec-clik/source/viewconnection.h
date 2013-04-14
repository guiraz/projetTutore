#ifndef VIEWCONNECTION_H
#define VIEWCONNECTION_H
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

#include "view.h"

class Controller;

class ViewConnection : public View
{
public:
    ViewConnection(Controller * parent);
    ~ViewConnection();
    void setView();
    void setComboBoxUser(const QString & user);

private:
    QPushButton _buttonQuit, _buttonNew, _buttonConnect;
    QLabel _label, _labelIcon;
    QComboBox _comboBox;
    Controller * _parent;
};

#endif // VIEWCONNECTION_H
