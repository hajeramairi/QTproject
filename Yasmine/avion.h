#ifndef AVION_H
#define AVION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Avion
{
public:
    Avion();
    Avion(int,int,QString,QString);
    int get_Numavion();
    int get_Capacite();
    QString get_Type();
    QString get_Disponibilite();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier (int Numavion,int Capacite,QString Type,QString Disponibilite);
    bool supprimer(int);
    QSqlQueryModel * afficher_trier();
    QSqlQueryModel * chercher(int);

private:
    int Numavion,Capacite;
    QString Type,Disponibilite;

};

#endif // AVION_H
