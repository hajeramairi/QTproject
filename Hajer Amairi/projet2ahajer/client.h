#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class client
{
    QString nom;
    QString prenom;
    int date_naissance ;
    QString cin;
public:
    client();
    client(QString,QString,int,QString );
    QString get_nom();
    QString get_prenom();
    int get_date_naissance();
    QString get_cin();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifierclient(QString,QString,int,QString);
    QSqlQueryModel *rechercher_client(QString);
    QSqlQueryModel * trier_client(QString);
};

#endif // CLIENT_H
