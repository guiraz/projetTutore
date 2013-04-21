#include "viewstat.h"
#include "controller.h"

ViewStat::ViewStat(Controller * parent) : View(), _parent(parent)
{
}

ViewStat::~ViewStat()
{
    _parent = NULL;
    delete _parent;

    delete[] _labels;
}

void ViewStat::setView()
{
    QIcon retourI, exitI;
    QString retourT("Retour"), exitT("Quitter");

    retourI.addPixmap(QPixmap("images/retour.png"));
    exitI.addPixmap(QPixmap("images/exit.png"));

    _buttonQuit.setParent(_parent);
    _buttonQuit.setGeometry((_parent->size().width()/2) + 3, (_parent->size().height()/2) + 3, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonQuit.setIcon(exitI);
    _buttonQuit.setIconSize(QSize(250,250));
    _buttonQuit.setText(exitT);
    _buttonQuit.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonQuit.setFont(QFont("Times New Roman", 24));
    _buttonQuit.setStyleSheet("background-color : #92C8FF;");
    _buttonQuit.setVisible(true);
    QObject::connect(&_buttonQuit, SIGNAL(clicked()), _parent, SLOT(quit()));

    _buttonReturn.setParent(_parent);
    _buttonReturn.setGeometry(5, (_parent->size().height()/2) + 3, (_parent->size().width()-15)/2, (_parent->size().height()-15)/2);
    _buttonReturn.setIcon(retourI);
    _buttonReturn.setIconSize(QSize(300,300));
    _buttonReturn.setText(retourT);
    _buttonReturn.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    _buttonReturn.setFont(QFont("Times New Roman", 24));
    _buttonReturn.setStyleSheet("background-color : #92C8FF;");
    _buttonReturn.setVisible(true);
    QObject::connect(&_buttonReturn, SIGNAL(clicked()), _parent, SLOT(menu()));

    _widgetStat.setParent(_parent);
    _widgetStat.setStyleSheet("background-color : #92C8FF;");
    _widgetStat.setGeometry(5,5,_parent->size().width()-10, (_parent->size().height()-15)/2);
    _widgetStat.setLayout(&_layout);
    _widgetStat.setVisible(true);

    QVector<int> tentatives = _parent->getTentatives();
    QVector<int> moyennes = _parent->getMoyennes();

    int nbLabels = (_parent->getNbExo()+1)*3;
    _labels = new QLabel[nbLabels];

    for(int i=0; i<nbLabels; i++)
    {
        _labels[i].setFont(QFont("Times New Roman", 18));
        _labels[i].setStyleSheet(".QLabel{background-color : pink;}");
        _labels[i].setAlignment(Qt::AlignCenter);
    }

    int compteur = 0;
    for(int i=0; i<_parent->getNbExo()+1; i++)
    {
        if(i==0)
        {
            _labels[compteur].setText(_parent->getUser());
            _layout.addWidget(&_labels[compteur], 0, 0);
            compteur++;
            _labels[compteur].setText("Nombre de tentatives :");
            _layout.addWidget(&_labels[compteur], 1, 0);
            compteur++;
            _labels[compteur].setText("Moyenne :");
            _layout.addWidget(&_labels[compteur], 2, 0);
            compteur++;
        }
        else
        {
            _labels[compteur].setText("Exercice "+QString::number(i)+" :");
            _layout.addWidget(&_labels[compteur], 0, i);
            compteur++;

            _labels[compteur].setText(QString::number(tentatives[i-1]));
            _layout.addWidget(&_labels[compteur], 1, i);
            compteur++;

            _labels[compteur].setText(QString::number(moyennes[i-1]));
            _layout.addWidget(&_labels[compteur], 2, i);
            compteur++;
        }
    }
}
