#ifndef ESCALE_H
#define ESCALE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class escale
{
public:
    escale();
    escale(int,int,QString,QString);
    int get_no_escale();
    int get_num_vol();
    QString get_date_depart();
    QString get_date_arrive();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString);
      QSqlQueryModel * rechercher(int );
private:


int no_escale;
int num_vol;
QString date_depart;
QString date_arrive;



};

#endif // VOL_H
