#ifndef CARTE_FID_H
#define CARTE_FID_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQueryModel>
#include <QTableView>
#include "stati.h"
class carte_fid
{
        QString id;
        int nbrv;
        int nbrp;
public:
    carte_fid();
    carte_fid(QString ,int ,int);

        QString get_id();
        int get_nbrv();
        int get_nbrp();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        bool modifiercarte(QString,int,int);
        QSqlQueryModel *rechercher_carte(int);
        QSqlQueryModel * trier_carte(QString);

};

#endif // CARTE_FID_H
