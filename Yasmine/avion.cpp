#include "avion.h"
#include <QDebug>
Avion::Avion()
{
    Numavion=0;
    Capacite=0;
    Type="";
    Disponibilite="";
}
Avion::Avion(int Numavion,int Capacite,QString Type,QString Disponibilite)
{
  this->Numavion=Numavion;
  this->Capacite=Capacite;
  this->Type=Type;
  this->Disponibilite=Disponibilite;
}
int Avion::get_Numavion(){return  Numavion;}
int Avion::get_Capacite(){return  Capacite;}
QString Avion::get_Type(){return  Type;}
QString Avion::get_Disponibilite(){return  Disponibilite;}


bool Avion::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(Numavion);
    QString res1= QString::number(Capacite);
    query.prepare("INSERT INTO Avion (NUMAVION,CAPACITE,TYPE,DISPONIBILITE) "
                        "VALUES (:Numavion,:Capacite,:Type,:Disponibilite)");
    query.bindValue(":Numavion", res);
    query.bindValue(":Capacite", res1);
    query.bindValue(":Type", Type);
    query.bindValue(":Disponibilite",Disponibilite);
    return    query.exec();

}
QSqlQueryModel * Avion::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from AVION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numavion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Capacite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Disponibilite"));

    return model;
}
QSqlQueryModel * Avion::afficher_trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from Avion order by NUMAVION asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numavion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Capacite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Disponibilite"));

    return model;
}
bool Avion::modifier(int Numavion,int Capacite,QString Type,QString Disponibilite)
{
    QString res = QString :: number (Numavion) ;
        QString res1= QString::number(Capacite);
        QSqlQuery q;
         q.prepare("UPDATE Avion set NUMAVION =:Numavion,CAPACITE=:Capacite ,TYPE=:Type,DISPONIBILITE=:Disponibilite where NUMAVION=:Numavion");
         q.bindValue(":Numavion",res);
         q.bindValue(":Capacite",res1);
         q.bindValue(":Type",Type);
         q.bindValue(":Disponibilite",Disponibilite);
        return    q.exec();


}
bool Avion::supprimer(int Numavionn)
{
QSqlQuery query;
QString res= QString::number(Numavionn);
query.prepare("DELETE from Avion where NUMAVION = :Numavion ");
query.bindValue(":Numavion", res);
return    query.exec();
}

QSqlQueryModel * Avion::chercher( int ref)
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare((QString("SELECT * from Avion where  NUMAVION = :Numavion  ")));

     query.bindValue(":Numavion",ref);
     query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numavion"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Capacite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Disponibilite"));

    return model;
}
