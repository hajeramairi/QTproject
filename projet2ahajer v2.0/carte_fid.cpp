#include "carte_fid.h"
#include "stati.h"

carte_fid::carte_fid()
{
   id="";
   nbrv=0;
   nbrp=0;
}
carte_fid::carte_fid(QString id,int nbrv,int nbrp)
{
    this->id=id;
    this->nbrv=nbrv;
    this->nbrp=nbrp;


}
QString carte_fid::get_id(){return id;}
int carte_fid:: get_nbrv(){return nbrv;}
int carte_fid::get_nbrp(){return nbrp;}
bool carte_fid::ajouter()
{
QSqlQuery f;

QString res0= QString::number(nbrv);
QString res1= QString::number(nbrp);

f.prepare("INSERT INTO CARTE_FID (ID_CARTE,NBR_VOYAGE,NBR_POINT) "
                    "VALUES (:id,:nbrv,:nbrp)");

f.bindValue(":id", id);
f.bindValue(":nbrv", res0);
f.bindValue(":nbrp", res1);


return    f.exec();
}
QSqlQueryModel * carte_fid::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CARTE_FID order by ID_CARTE ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CARTE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_VOYAGE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE_POINTS"));


    return model;
}
bool carte_fid::supprimer(QString id)
{
QSqlQuery f;

f.prepare("Delete from CARTE_FID where ID_CARTE = :id ");
f.bindValue(":id", id);
return    f.exec();
}
bool carte_fid::modifiercarte(QString id,int nbrv,int nbrp)
{
    QSqlQuery f;
QString res= QString:: number(nbrv);
QString res1= QString:: number(nbrp);
         f.prepare("UPDATE CARTE_FID set ID_CARTE =:id,NBR_VOYAGE=:nbrv,NBR_POINT=:nbrp where ID_CARTE =:id ");
         f.bindValue(":id",id);
        f.bindValue(":nbrv",res);
        f.bindValue(":nbrp",res1);

        return    f.exec();


}

 QSqlQueryModel * carte_fid::rechercher_carte(int nbrv)
{

     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery f;
     f.prepare("Select * from CARTE_FID where NBR_VOYAGE  =:nbrv");
     f.bindValue(":nbrv",nbrv);
     f.exec();
     model->setQuery(f);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CARTE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBR_VOYAGE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE_POINTS"));

         return model;


}
