#include "mainwindow.h"

MainWindow::MainWindow():QWidget()
{
    /*Definition de la fenetre */

    //setStyleSheet("background-color:cyan;"); -> tout pourris
    //setFixedSize(800,600);


    /*Definition des bouton */

    mw_quitter = new QPushButton(this);
    mw_quitter->setGeometry(1500,10,100,50);
    mw_quitter->setText("QUITTER");

    /*SLOTS*/

    QObject::connect(mw_quitter,SIGNAL(clicked()),qApp,SLOT(quit()));

}

MainWindow::~MainWindow()
{
}
