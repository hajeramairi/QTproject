#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mysystem= new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    int Numbillet = ui->lineEdit_numb->text().toInt();
    int Numvoyageur = ui->lineEdit_numv->text().toInt();
    QString Nom= ui->lineEdit_nom->text();
    QString Prenom= ui->lineEdit_prenom->text();
    QString Destination= ui->lineEdit_des->text();
    int Depart= ui->lineEdit_date->text().toInt();
    int Arrivee= ui->lineEdit_datea->text().toInt();
    Billet b (Numbillet,Numvoyageur,Nom,Prenom,Destination,Depart,Arrivee);
  bool test=b.ajouter();

  if(test)
{
      ui->tablebill->setModel(tempbill.afficher());//refresh
     mysystem->showMessage(tr("Notification"),tr("Billet ajouté avec success"));

QMessageBox::information(nullptr, QObject::tr("Ajouter un billet"),
                  QObject::tr("billet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un billet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    int Numbillet = ui->lineEdit_7->text().toInt();
    bool test=tempbill.supprimer(Numbillet);
    if(test)
    {ui->tablebill->setModel(tempbill.afficher());//refresh
        mysystem->showMessage(tr("Notification"),tr("Billet supprimé"));

        QMessageBox::information(nullptr, QObject::tr("Supprimer un billet"),
                    QObject::tr("billet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un billet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    int Numbillet = ui->lineEdit_numb_2->text().toInt();
    int Numvoyageur = ui->lineEdit_numv_2->text().toInt();
    QString Nom= ui->lineEdit_nom_2->text();
    QString Prenom= ui->lineEdit_prenom_2->text();
    QString Destination= ui->lineEdit_des_2->text();
    int Depart= ui->lineEdit_date_2->text().toInt();
    int Arrivee= ui->lineEdit_datea_2->text().toInt();

    bool test = tempbill.modifier(Numbillet,Numvoyageur,Nom,Prenom,Destination,Depart,Arrivee);
    if (test)
    {
        ui->tablebill->setModel( tempbill.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifiée avec sucess!"),
        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

      }

    else
        QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_4_clicked()
{
    int Numavion = ui->lineEdit->text().toInt();
    int Capacite = ui->lineEdit_2->text().toInt();
    QString Type= ui->lineEdit_3->text();
    QString Disponibilite= ui->lineEdit_4->text();
    Avion a (Numavion,Capacite,Type,Disponibilite);
  bool test=a.ajouter();
  if(test)
{ui->tableav->setModel(tempav.afficher());//refresh
     mysystem->showMessage(tr("Notification"),tr("Avion ajouté avec success"));
QMessageBox::information(nullptr, QObject::tr("Ajouter un avion"),
                  QObject::tr("Avion ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un avion"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    int Numavion = ui->lineEdit_5->text().toInt();
    int Capacite = ui->lineEdit_6->text().toInt();
    QString Type= ui->lineEdit_8->text();
    QString Disponibilite= ui->lineEdit_9->text();

    bool test = tempav.modifier(Numavion,Capacite,Type,Disponibilite);
    if (test)
    {
        ui->tableav->setModel( tempav.afficher());
        QMessageBox::information(nullptr, QObject::tr("Avion modifié avec sucess !"),
        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

      }

    else
        QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
        QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()
{
    int Numavion = ui->lineEdit_10->text().toInt();
    bool test=tempav.supprimer(Numavion);
    if(test)
    {ui->tableav->setModel(tempav.afficher());//refresh
        mysystem->showMessage(tr("Notification"),tr("Avion supprimé"));
        QMessageBox::information(nullptr, QObject::tr("Supprimer un avion"),
                    QObject::tr("Avion supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un avion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tablebill->setModel( tempbill.afficher_trier());

}

void MainWindow::on_pushButton_8_clicked()
{
     ui->tableav->setModel( tempav.afficher_trier());
}


void MainWindow::on_pushButton_9_clicked()
{
    int num = ui->lineEdit_11->text().toInt();
    ui->tableav->setModel(tempav.chercher(num));

}

void MainWindow::on_pushButton_10_clicked()
{
    int num= ui->lineEdit_12->text().toInt();
    ui->tablebill->setModel(tempbill.chercher(num));
}
