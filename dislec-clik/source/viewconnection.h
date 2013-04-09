#ifndef VIEWCONNECTION_H
#define VIEWCONNECTION_H
#include "view.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QObject>
#include <QLabel>
#include <QComboBox>

class ViewConnection : public View
{
public:
    ViewConnection(QWidget * parent);
    ~ViewConnection();
    void setView();

private:
    QPushButton _buttonQuit;
    QLabel _label;
    QComboBox _comboBox;
};

#endif // VIEWCONNECTION_H
