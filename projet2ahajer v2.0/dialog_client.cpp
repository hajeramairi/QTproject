#include "dialog_client.h"
#include "ui_dialog_client.h"
#include"client.h"
#include<QMessageBox>
#include <QDebug>
#include<QTableView>
#include <QSystemTrayIcon>

Dialog_client::Dialog_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_client)
{
    ui->setupUi(this);
    mysystemTrayIcon = new QSystemTrayIcon(this);
    mysystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    mysystemTrayIcon->setVisible(true);
      ui->tableclient->setModel(tempclient.afficher());
}

Dialog_client::~Dialog_client()
{
    delete ui;
}

void Dialog_client::on_pushButton_4_clicked()
{
    QString nom=ui->lineEdit_nom->text();
     QString prenom=ui->lineEdit_prenom->text();
    int date_naissance= ui->lineEdit_date->text().toInt();
    QString cin=ui->lineEdit_cin->text();

  client c (nom,prenom,date_naissance,cin);

  bool test=c.ajouter();
  if(test)
{ui->tableclient->setModel(tempclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog_client::on_pushButton_clicked()
{
    QString  nom = ui->lineEdit1->text();
    QString  prenom = ui->lineEdit2->text();
       int date_naissance=ui->lineEdit3->text().toInt();
        QString cin = ui->lineEdit4->text();


         bool test = tempclient.modifierclient(nom,prenom,date_naissance,cin);

             if (test)

             {

                  ui->tableclient->setModel( tempclient.afficher());



                 QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }




void Dialog_client::on_pushButton_2_clicked()
{ QString id = ui->lineEdit_cin->text();
    bool test=tempclient.supprimer(id);
    if(test)
    {ui->tableclient->setModel(tempclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                    QObject::tr("carte supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un carte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void Dialog_client::on_pushButton_3_clicked()
{
    QString cin ;
        cin=ui->lineEdit_2->text();
    bool test= true;
    if(test==(true))
    {
      ui->tableclient_5->setModel(tempclient.rechercher_client(cin));
    QMessageBox::information(nullptr, QObject::tr("le client existe  !"),
                QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

    }

}



void Dialog_client::on_pushButton_5_clicked()
{

    QString nom ;

    bool test= true;
    if(test==(true))
    {
      ui->tabletrie->setModel(tempclient.trier_client(nom));
    QMessageBox::information(nullptr, QObject::tr("le client est trié  !"),
                QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void Dialog_client::on_showmessagepushbutton_clicked()
{
    mysystemTrayIcon->showMessage(tr("Notification"),tr("Ajout d'un nouveau client"));
}
