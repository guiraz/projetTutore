#ifndef VIEW_H
#define VIEW_H
#include <QString>

class View
{
public:
    View();
    virtual ~View();
    virtual void setView() = 0;

    //ViewConnection*****************************
    virtual void setComboBoxUser(const QString & user);
    virtual int getCurrent();

    //ViewNewUser********************************
    virtual void erreur(bool affiche);
    virtual bool correctName();
    virtual QString getName();

    //ViewMenuExercices**************************
    virtual void changeTextButton(QString exo1, QString exo2);
};

#endif // VIEW_H
