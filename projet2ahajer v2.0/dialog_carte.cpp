#include "dialog_carte.h"
#include "ui_dialog_carte.h"
#include"carte_fid.h"
#include<QMessageBox>
#include <QDebug>
#include<QTableView>
#include<QSystemTrayIcon>
#include "stati.h"


Dialog_carte::Dialog_carte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_carte)
{
    ui->setupUi(this);
    mysystemTrayIcon = new QSystemTrayIcon(this);
    mysystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    mysystemTrayIcon->setVisible(true);
    ui->tablecarte->setModel(tempfid.afficher());


}



Dialog_carte::~Dialog_carte()
{
    delete ui;
}

void Dialog_carte::on_pushButton_clicked()
{

        QString id=ui->lineEdit->text();
        int nbrv= ui->lineEdit_2->text().toInt();
        int nbrp=ui->lineEdit_3->text().toInt();

      carte_fid f (id, nbrv,nbrp);

      bool test=f.ajouter();
      if(test)
    {ui->tablecarte->setModel(tempfid.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                      QObject::tr("carte ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog_carte::on_pushButton_3_clicked()
{
    QString id = ui->lineEdit_7->text();
        bool test=tempfid.supprimer(id);
        if(test)
        {ui->tablecarte->setModel(tempfid.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer une carte"),
                        QObject::tr("carte supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un carte"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog_carte::on_pushButton_2_clicked()
{
    QString  id = ui->lineEdit_4->text();
       int nbrv=ui->lineEdit_5->text().toInt();
        int nbrp= ui->lineEdit_6->text().toInt();


         bool test = tempfid.modifiercarte( id,nbrv,nbrp);

             if (test)

             {

                  ui->tablecarte->setModel( tempfid.afficher());



                 QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog_carte::on_pushButton_4_clicked()
{
    int nbrv;

        nbrv=ui->lineEdit_8->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tablecarte_3->setModel(tempfid.rechercher_carte(nbrv));
    QMessageBox::information(nullptr, QObject::tr("la carte existe  !"),
                QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

        QMessageBox::critical(nullptr, QObject::tr("la carte n'existe pas !"),

                    QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

}





void Dialog_carte::on_showmessagepuchbutton_clicked()
{
    mysystemTrayIcon->showMessage(tr("Notification"),tr("Ajout d'une nouvelle carte"));
}


void Dialog_carte::on_pushButton_5_clicked()
{


}
