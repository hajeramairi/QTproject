#include "connection.h"
#include <QSqlError>
#include<QString>
connection::connection(){
                      }
bool connection::ouvrirconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("karim");
                           db.setUserName("karim");//inserer nom de l'utilisateur
                           db.setPassword("karim");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void connection::fermerconnect()
{db.close();}
