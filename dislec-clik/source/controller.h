#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMessageBox>
#include "view.h"
#include "model.h"
#include "viewconnection.h"

#include <iostream>

using namespace std;

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    MainWindow();
    ~MainWindow();

private:
    View * _v;
    Model * _m;

    void removeView();
    void removeModel();

private slots:
    void quit();

};

#endif // MAINWINDOW_H
