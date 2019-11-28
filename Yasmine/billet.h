#ifndef BILLET_H
#define BILLET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Billet
{
public:
    Billet();
    Billet(int,int,QString,QString,QString,int,int);
    int get_Numbillet();
    int get_Numvoyageur();
    QString get_Nom();
    QString get_Prenom();
    QString get_Destination();
    int get_Depart();
    int get_Arrivee();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int Numbillet,int Numvoyageur,QString Nom,QString Prenom,QString Destination,int Depart,int Arrivee);
    bool supprimer(int);
    QSqlQueryModel * afficher_trier();
    QSqlQueryModel * chercher(int);
private:
    int Numbillet, Numvoyageur,Depart,Arrivee;
    QString Nom,Prenom,Destination;

};

#endif // BILLET_H
