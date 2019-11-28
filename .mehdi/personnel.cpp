#include "personnel.h"
#include <QDebug>
Personnel::Personnel()
{
NumP=0;
Nom="";
Fonction="";
Salaire=0;
Chef=0;
}
Personnel::Personnel(int NumP,QString Nom,QString Fonction,int Salaire,int Chef)
{
  this->NumP=NumP;
  this->Nom=Nom;
  this->Fonction=Fonction;
  this->Salaire=Salaire;
  this->Chef=Chef;

}
int Personnel::get_NumP(){return  NumP;}
QString Personnel::get_Nom(){return Nom;}
QString Personnel::get_Fonction(){return Fonction;}
int Personnel::get_Salaire(){return  Salaire;}
int Personnel::get_Chef(){return Chef;}

bool Personnel::ajouter()
{
QSqlQuery query;
QString res= QString::number(NumP);
QString res2= QString::number(Chef);

query.prepare("INSERT INTO Personnel (NumP,NOM,FONCTION,SALAIRE,Chef)"
              "VALUES (:NumP, :Nom, :Fonction, :Salaire, :Chef)");
query.bindValue(":NumP", res);
query.bindValue(":Nom", Nom);
query.bindValue(":Fonction", Fonction);
query.bindValue(":Salaire", Salaire);
query.bindValue(":Chef", res2);


return    query.exec();
}

QSqlQueryModel * Personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fonction "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Chef"));
    return model;
}

bool Personnel::supprimer(int NumPP)
{
QSqlQuery query;
QString res= QString::number(NumPP);
query.prepare("Delete from Personnel where NumP = :NumP ");
query.bindValue(":NumP", res);
return    query.exec();
}
//

bool Personnel :: modifier(int NumPP,int SalaireN)
{
QSqlQuery query;
QString res= QString::number(NumPP);
QString res1= QString::number(SalaireN);
query.prepare("UPDATE Personnel set Salaire = :SalaireN where NumP = :NumP");
query.bindValue(":NumP", res);
query.bindValue(":SalaireN", SalaireN);
return    query.exec();

}

QSqlQueryModel * Personnel::chercher(int NumPP)
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res= QString::number(NumPP);

    model->setQuery("SELECT * from Personnel where NumP = :NumP");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Fonction "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Chef"));
        return model;

}
