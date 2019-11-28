#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Departement
{public:
    Departement();
    Departement(int,QString,int);
    QString get_Emplacement();
    int get_NumDep();
    int get_NbrP();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString Emplacement;
    int NumDep,NbrP;
};

#endif // ETUDIANT_H
