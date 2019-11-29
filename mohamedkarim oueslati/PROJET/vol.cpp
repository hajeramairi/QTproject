#include "vol.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

vol::vol()
{
    num_vol=0;
     date_depart="";
     date_arrive="";
     heure_arrive="";
     heure_depart="";
    no_escale=0;
    num_billet=0;

}
vol::vol(int num_vol,QString date_depart,QString date_arrive,QString heure_arrive,QString heure_depart,int no_escale,int num_billet)
{this->num_vol=num_vol;
this->date_depart=date_depart;
this->date_arrive=date_arrive;
this->heure_arrive=heure_arrive;
this->heure_depart=heure_depart;
    this->no_escale=no_escale;
    this->num_billet=num_billet;

}
QString vol:: get_date_depart(){return date_depart;}
QString vol:: get_heure_depart(){return heure_depart;}
QString vol:: get_date_arrive(){return date_arrive;}
QString vol:: get_heure_arrive(){return heure_arrive;}
int vol:: get_no_escale(){return no_escale; }
int vol:: get_num_vol(){return num_vol;}
int vol::get_num_billet(){return num_billet;}

bool vol:: ajouter()
{
    QSqlQuery query;
    QString res= QString::number(num_vol);
    QString res2= QString::number(no_escale);
     QString res3= QString::number(num_billet);

    query.prepare("INSERT INTO VOL (NUM_VOL,DATE_DEPART,DATE_ARRIVE,HEURE_DEPART,HEURE_ARRIVE,NO_ESCALE,NUM_BILLET) "
                        "VALUES (:num_vol,:date_depart,:date_arrive,:heure_depart,:heure_arrive,:no_escale,:num_billet)");
    query.bindValue(":num_vol", res);
    query.bindValue(":date_depart",date_depart);
    query.bindValue(":date_arrive",date_arrive);
    query.bindValue(":heure_depart",heure_depart);
    query.bindValue(":heure_arrive",heure_arrive);
    query.bindValue(":no_escale",res2);
    query.bindValue(":num_billet",res3);
    return    query.exec();
    }

QSqlQueryModel * vol::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOL");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_VOL"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE_ARRIVE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("HEURE_DEPART"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NO_ESCALE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_BILLET"));
    return model;
}
bool vol::supprimer(int num_vol)
{
QSqlQuery query;
QString res= QString::number(num_vol);
query.prepare("Delete from VOL where NUM_VOL = :num_vol ");
query.bindValue(":num_vol", res);
return    query.exec();
}
bool vol:: modifier(int num_vol,QString date_depart,QString date_arrive,QString heure_arrive,QString heure_depart,int no_escale,int num_billet)
{QSqlQuery query;
    QString res= QString::number(num_vol);
    QString res2= QString::number(no_escale);
    QString res3= QString::number(num_billet);

         query.prepare("UPDATE VOL set NUM_VOL=:num_vol,DATE_DEPART=:date_depart,DATE_ARRIVE=:date_arrive,HEURE_DEPART=:heure_depart,HEURE_ARRIVE=:heure_arrive,NO_ESCALE=:no_escale,NUM_BILLET=:num_billet where NUM_VOL= :num_vol");
                   query.bindValue(":num_vol", res);
                   query.bindValue(":date_depart",date_depart);
                   query.bindValue(":date_arrive",date_arrive);
                   query.bindValue(":heure_depart",heure_depart);
                   query.bindValue(":heure_arrive",heure_arrive);
                   query.bindValue(":no_escale",res2);
                       query.bindValue(":num_billet",res3);
        return    query.exec();



}
QSqlQueryModel * vol::Rechercher(int num_vol)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from VOL where NUM_VOL =:num_vol");
    query.bindValue(":num_vol",num_vol);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_VOL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEPART"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE_ARRIVE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("HEURE_DEPART"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NO_ESCALE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_BILLET"));
        return model;
   }
QSqlQueryModel * vol::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOL order by NUM_VOL asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_VOL"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE_ARRIVE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("HEURE_DEPART"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NO_ESCALE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_BILLET"));
    return model;
}



