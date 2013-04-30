#include "viewexercice.h"
#include "controller.h"

ViewExercice::ViewExercice(Controller * parent)
    : View(), _parent(parent)
{
}

ViewExercice::~ViewExercice()
{
    _parent = NULL;
    delete _parent;

    delete _mapper;
}

void ViewExercice::setView()
{
    int x = (_parent->size().width()-15)/2;
    int y = (_parent->size().height()-15)/2;

    _mapper = new QSignalMapper(_parent);
    _mapper->connect(_mapper, SIGNAL(mapped(int)), _parent, SLOT(propEvent(int)));

    _buttonProp1.setParent(_parent);
    _buttonProp1.setGeometry(5, 5, x, y);
    _buttonProp1.setFont(QFont("Times New Roman", 24));
    _buttonProp1.setStyleSheet("background-color : #92C8FF;");
    _buttonProp1.setVisible(false);
    _mapper->connect( &_buttonProp1, SIGNAL( clicked() ), SLOT( map() ) );
    _mapper->setMapping( &_buttonProp1, 1 );

    _buttonProp2.setParent(_parent);
    _buttonProp2.setGeometry((_parent->size().width()/2) + 3, 5, x, y);
    _buttonProp2.setFont(QFont("Times New Roman", 24));
    _buttonProp2.setStyleSheet("background-color : #92C8FF;");
    _buttonProp2.setVisible(false);
    _mapper->connect( &_buttonProp2, SIGNAL( clicked() ), SLOT( map() ) );
    _mapper->setMapping( &_buttonProp2, 2 );

    _buttonProp3.setParent(_parent);
    _buttonProp3.setGeometry(5, (_parent->size().height()/2) + 3, x, y);
    _buttonProp3.setFont(QFont("Times New Roman", 24));
    _buttonProp3.setStyleSheet("background-color : #92C8FF;");
    _buttonProp3.setVisible(false);
    _mapper->connect( &_buttonProp3, SIGNAL( clicked() ), SLOT( map() ) );
    _mapper->setMapping( &_buttonProp3, 3 );

    _buttonProp4.setParent(_parent);
    _buttonProp4.setGeometry((_parent->size().width()/2) + 3, (_parent->size().height()/2) + 3, x, y);
    _buttonProp4.setFont(QFont("Times New Roman", 24));
    _buttonProp4.setStyleSheet("background-color : #92C8FF;");
    _buttonProp4.setVisible(false);
    _mapper->connect( &_buttonProp4, SIGNAL( clicked() ), SLOT( map() ) );
    _mapper->setMapping( &_buttonProp4, 4 );

    _label1.setParent(_parent);
    _label1.setText(_parent->getExoName());
    _label1.setFont(QFont("Times New Roman", 72));
    _label1.setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    _label1.setGeometry(3,3,_parent->size().width()-6, (_parent->size().height()-12)/3);
    _label1.setVisible(true);

    _label2.setParent(_parent);
    _label2.setText(_parent->getExoDesc());
    _label2.setFont(QFont("Times New Roman", 24));
    _label2.setAlignment(Qt::AlignCenter);
    _label2.setGeometry(3,(_parent->size().height()-12)/3+6,_parent->size().width()-6, (_parent->size().height()-12)/3);
    _label2.setVisible(true);

    _label3.setParent(_parent);
    _label3.setText("Touches la fenêtre pour commencer.");
    _label3.setFont(QFont("Times New Roman", 12));
    _label3.setAlignment(Qt::AlignHCenter|Qt::AlignTop);
    _label3.setGeometry(3,((_parent->size().height()-12)/3)*2+9,_parent->size().width()-6, (_parent->size().height()-12)/3);
    _label3.setVisible(true);
}

void ViewExercice::setButtonExo(QStringList list)
{
    _label1.setVisible(false);
    _label2.setVisible(false);
    _label3.setVisible(false);

    _buttonProp1.setText(list[0]);
    _buttonProp1.setVisible(true);
    _buttonProp2.setText(list[1]);
    _buttonProp2.setVisible(true);
    _buttonProp3.setText(list[2]);
    _buttonProp3.setVisible(true);
    _buttonProp4.setText(list[3]);
    _buttonProp4.setVisible(true);
}

void ViewExercice::setMarkPage(QString mark)
{
    _label1.setVisible(true);
    _label2.setVisible(true);
    _label3.setVisible(true);
    _label1.setText("Résultat");
    _label2.setText(mark+"/10");
    _label3.setText("Touches la fenêtre pour terminer.");

    _buttonProp1.setVisible(false);
    _buttonProp2.setVisible(false);
    _buttonProp3.setVisible(false);
    _buttonProp4.setVisible(false);
}
