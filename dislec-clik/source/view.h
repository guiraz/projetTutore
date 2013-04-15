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

    //ViewNewUser********************************
    virtual void erreur(bool affiche);
};

#endif // VIEW_H
