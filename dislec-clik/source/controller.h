#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define WIN_WIDTH 1024
#define WIN_HEIGHT 768

#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include "model.h"
#include "view.h"

#include <iostream>
using namespace std;

class Controller : public QWidget
{
    Q_OBJECT
    
public:
    Controller();
    ~Controller();
    void setUser();

private:
    View * _v;
    Model * _m;

    void removeView();
    void removeModel();

private slots:
    void quit();
    void newUser();
    void connect();

};

#endif // MAINWINDOW_H
