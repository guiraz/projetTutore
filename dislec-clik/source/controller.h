#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define WIN_WIDTH 1024
#define WIN_HEIGHT 768

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <iostream>

#include "modelconnection.h"
#include "viewconnection.h"
#include "viewnewuser.h"
#include "db.h"

class View;
class Model;

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
    Db _db;

    void removeView();
    void removeModel();

private slots:
    void quit();

    //Connection*****
    void newUser();
    void connect();

    //New User****
    void newUserName(QString name);
    void retour();

};

#endif // MAINWINDOW_H
