#include "escale.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

escale::escale()
{

    no_escale=0;
    num_vol=0;
    date_depart="";
    date_arrive="";

}
escale::escale(int no_escale,int num_vol,QString date_depart,QString date_arrive )
{
    this->no_escale=no_escale;
    this->num_vol=num_vol;
    this->date_depart=date_depart;
    this->date_arrive=date_arrive;

}

int escale:: get_no_escale(){return no_escale; }


bool escale:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(no_escale);
        QString res1= QString::number(num_vol);
    query.prepare("INSERT INTO ESCALE (NO_ESCALE,NUM_VOL,DATE_DEPART,DATE_ARRIVE) "
                        "VALUES ( :no_escale,:num_vol,:date_depart,:date_arrive)");
    query.bindValue(":no_escale", res);
    query.bindValue(":num_vol", res1);
    query.bindValue(":date_depart",date_depart);
    query.bindValue(":date_arrive",date_arrive);

    return    query.exec();
    }

QSqlQueryModel *escale::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ESCALE  order by NO_ESCALE desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NO_ESCALE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_VOL"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEPART"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));

    return model;
}
bool escale::supprimer(int no_escale)
{
QSqlQuery query;
QString res= QString::number(no_escale);

query.prepare("Delete from ESCALE where NO_ESCALE = :NO_escale ");
query.bindValue(":NO_escale", res);
return    query.exec();
}
bool escale:: modifier(int no_escale ,int num_vol, QString date_depart, QString date_arrive )
{QSqlQuery query;
    QString res= QString::number(num_vol);
    QString res2= QString::number(no_escale);

         query.prepare("UPDATE ESCALE set NO_ESCALE=:no_escale,NUM_VOL=:num_vol,DATE_DEPART=:date_depart,DATE_ARRIVE=:date_arrive where NO_ESCALE= :no_escale ");
              query.bindValue(":no_escale", res2);

              query.bindValue(":num_vol", res);

                   query.bindValue(":date_depart",date_depart);
                   query.bindValue(":date_arrive",date_arrive);


        return    query.exec();

}
QSqlQueryModel * escale::rechercher(int no_escale)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from ESCALE where NO_ESCALE =:no_escale");
    query.bindValue(":no_escale",no_escale);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NO_ESCALE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_VOL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEPART"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));

        return model;
   }



