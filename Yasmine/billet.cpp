#include "billet.h"
#include <QDebug>
Billet::Billet()
{
    Numbillet=0;
    Numvoyageur=0;
    Nom="";
    Prenom="";
    Destination="";
    Depart=0;
    Arrivee=0;
}
Billet::Billet(int Numbillet,int Numvoyageur,QString Nom,QString Prenom,QString Destination,int Depart,int Arrivee )
{
  this->Numbillet=Numbillet;
  this->Numvoyageur=Numvoyageur;
  this->Nom=Nom;
  this->Prenom=Prenom;
  this->Destination=Destination;
  this->Depart=Depart;
  this->Arrivee=Arrivee;
}
QString Billet::get_Nom(){return  Nom;}
QString Billet::get_Prenom(){return Prenom;}
QString Billet::get_Destination(){return Destination;}
int Billet::get_Depart(){return  Depart;}
int Billet::get_Arrivee(){return  Arrivee;}
int Billet::get_Numbillet(){return  Numbillet;}
int Billet::get_Numvoyageur(){return  Numvoyageur;}

bool Billet::ajouter()
{
QSqlQuery query;
QString res= QString::number(Numbillet);
 QString res1= QString::number(Numvoyageur);
  QString res2= QString::number(Depart);
   QString res3= QString::number(Arrivee);
query.prepare("INSERT INTO billet (NUMBILLET,NUMVOYAGEUR, NOM, PRENOM,DESTINATION,DEPART,ARRIVEE) "
                    "VALUES (:Numbillet, :Numvoyageur, :Nom, :Prenom, :Destination, :Depart, :Arrivee)");
query.bindValue(":Numbillet", res);
query.bindValue(":Numvoyageur", res1);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":Destination", Destination);
query.bindValue(":Depart", res2);
query.bindValue(":Arrivee", res3);
return    query.exec();
}
QSqlQueryModel * Billet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from billet");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numbillet"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numvoyageur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Destination"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Depart"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Arrivee"));
    return model;
}
QSqlQueryModel * Billet::afficher_trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from billet order by NUMBILLET asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numbillet"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numvoyageur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Destination"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Depart"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Arrivee"));
    return model;
}
bool Billet::modifier(int Numbillet,int Numvoyageur,QString Nom,QString Prenom,QString Destination,int Depart,int Arrivee)
{
    QString res = QString :: number (Numbillet) ;
    QString res1= QString::number(Numvoyageur);
    QString res2 = QString :: number (Depart) ;
    QString res3= QString::number(Arrivee);
        QSqlQuery q;
         q.prepare("UPDATE billet set NUMBILLET=:Numbillet,NUMVOYAGEUR=:Numvoyageur,NOM=:Nom,PRENOM=:Prenom,DESTINATION=:Destination,DEPART=:Depart,ARRIVEE=:Arrivee where NUMBILLET=:Numbillet");
         q.bindValue(":Numbillet",res);
         q.bindValue(":Numvoyageur",res1);
         q.bindValue(":Nom",Nom);
         q.bindValue(":Prenom",Prenom);
         q.bindValue(":Destination",Destination);
         q.bindValue(":Depart",res2);
         q.bindValue(":Arrivee",res3);
        return    q.exec();


}
bool Billet::supprimer(int Numbillett)
{
QSqlQuery query;
QString res= QString::number(Numbillett);
query.prepare("DELETE from Billet where NUMBILLET = :Numbillet ");
query.bindValue(":Numbillet", res);
return    query.exec();
}
QSqlQueryModel * Billet::chercher( int ref)
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare((QString("SELECT * from Billet where  NUMBILLET= :Numbillet ")));

     query.bindValue(":Numbillet",ref);
     query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numbillet"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numvoyageur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Destination"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Depart"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Arrivee"));

    return model;
}
