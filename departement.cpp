#include "departement.h"
#include <QDebug>
Departement::Departement()
{
NumDep=0;
NbrP=0;
Emplacement="";

}
Departement::Departement(int NumDep,QString Emplacement,int NbrP)
{
  this->NumDep=NumDep;
  this->NbrP=NbrP;
  this->Emplacement=Emplacement;

}
int Departement::get_NumDep(){return  NumDep;}
int Departement::get_NbrP(){return NbrP;}
QString Departement::get_Emplacement(){return Emplacement;}

bool Departement::ajouter()
{
QSqlQuery query;
QString res= QString::number(NumDep);
QString res2= QString::number(NbrP);
query.prepare("INSERT INTO Departement (NumDep,NbrP,Emplacement,SALAIRE,Chef)"
              "VALUES (:NumDep, :Emplacement, :NbrP)");
query.bindValue(":NumDep", res);
query.bindValue(":NbrP", NbrP);
query.bindValue(":Emplacement", Emplacement);



return    query.exec();
}

QSqlQueryModel * Departement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Departement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumDep"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NbrP"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Emplacement "));
}

bool Departement::supprimer(int NumDep)
{
QSqlQuery query;
QString res= QString::number(NumDep);
query.prepare("Delete from Departement where NumDep = :NumDep ");
query.bindValue(":NumDep", res);
return    query.exec();
}

