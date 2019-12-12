#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTableView>


class vol
{
public:
    vol();
    vol(int,QString,QString,QString,QString,int,int);
    int get_num_vol();
    QString get_date_depart();
    QString get_heure_depart();
    QString get_date_arrive();
    QString get_heure_arrive();
    int get_no_escale();
    int get_num_billet();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,int,int);
    QSqlQueryModel * Rechercher(int );
    QSqlQueryModel * afficher_tri();
private:
QString date_depart;
QString date_arrive;
QString heure_arrive;
QString heure_depart;
int num_vol;
int no_escale;
int num_billet;



};

#endif // VOL_H
