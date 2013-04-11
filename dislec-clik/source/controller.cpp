#include "mainwindow.h"

MainWindow::MainWindow() : QWidget()
{
    this->setPalette(QPalette(QColor(192,192,255)));
    _v = new ViewConnection(this);
    _v->setView();
}

MainWindow::~MainWindow()
{
    removeView();
    removeModel();
}

void MainWindow::removeView()
{
    delete _v;
}

void MainWindow::removeModel()
{
    //delete _m;
}

void MainWindow::quit()
{
    if(QMessageBox::warning(NULL, "Fermeture du programme", "Etes vous sure de vouloir arrêter le programme?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        this->close();
}
