#include "client.h"

client::client()
{
  nom="";
  prenom="";
  date_naissance=0;
   cin="";
}
client::client(QString nom,QString prenom,int date_naissance,QString cin)
{
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date_naissance;
    this->cin=cin;
}
QString client:: get_nom(){return nom;}
QString client::get_prenom(){return prenom;}
int client::get_date_naissance(){return date_naissance;}
QString client::get_cin(){return cin;}
bool client::ajouter()
{
    QSqlQuery c;

    QString res= QString::number(date_naissance);


    c.prepare("INSERT INTO CLIENT (NOM,PRENOM,DATE_DE_NAISSANCE,NUM_CIN) "
                        "VALUES (:nom,:prenom,:date_naissance,:cin)");

    c.bindValue(":nom", nom);
    c.bindValue(":prenom", prenom);
    c.bindValue(":date_naissance", res);
    c.bindValue(":cin", cin);

    return    c.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery c;
    c.prepare("Select * from CLIENT order by NUM_CIN");
    c.bindValue(":cin",cin);
    c.exec();
model->setQuery("select * from CLIENT  ");
model->setQuery(c);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(1,Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_CIN"));
    return model;
}
bool client::supprimer(QString id)
{
QSqlQuery c;

c.prepare("Delete from CLIENT where NUM_CIN = :NUM_cin");
c.bindValue(":NUM_cin", id);
return    c.exec();
}
bool client::modifierclient(QString nom, QString prenom, int date_naissance,QString cin )
{
    QSqlQuery c;
QString res= QString:: number(date_naissance);
         c.prepare("UPDATE CLIENT set NOM =:nom,PRENOM=:prenom,DATE_DE_NAISSANCE=:date_naissance,NUM_CIN=:cin where NUM_CIN =:cin ");
         c.bindValue(":nom",nom);
        c.bindValue(":prenom",prenom);
        c.bindValue(":date_naissance",res);
        c.bindValue(":cin",cin);

        return    c.exec();
}


QSqlQueryModel * client::rechercher_client(QString cin)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery c;
    c.prepare("Select * from CLIENT where NUM_CIN=:cin");
    c.bindValue(":cin",cin);
    c.exec();
    model->setQuery(c);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_CIN"));

        return model;


}
QSqlQueryModel * client::trier_client(QString nom)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery c;
    c.prepare("Select * from CLIENT order by NOM");
    c.bindValue(":nom",nom);
    c.exec();
    model->setQuery(c);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_CIN"));

        return model;


}
