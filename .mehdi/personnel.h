#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Personnel
{public:
    Personnel();
    Personnel(int,QString,QString,int,int);
    QString get_Nom();
    QString get_Fonction();
    int get_NumP();
    int get_Salaire();
    int get_SalaireN();
    int get_Chef();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int);
    QSqlQueryModel * chercher(int);
private:
    QString Nom,Fonction;
    int NumP,Salaire,Chef;
};

#endif // ETUDIANT_H
