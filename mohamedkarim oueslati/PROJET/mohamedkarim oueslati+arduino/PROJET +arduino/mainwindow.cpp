#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include"vol.h"
#include <QMessageBox>
#include <QDebug>
#include<QSystemTrayIcon>
#include <QPrinter>
#include <QPrintDialog>
#include "arduino.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabvol->setModel(tmpvol.afficher());
    mysystem= new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
  /* data=A.read_from_arduino();
    QString x=QString::fromStdString(data.toStdString());
     ui->label_38->setText(x) ;*/

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_ajouterv_clicked()
{
    int num_vol= ui->lineEdit->text().toInt();
        QString date_depart= ui->lineEdit_2->text();
        QString heure_depart=ui->lineEdit_4->text();
        QString date_arrive=ui->lineEdit_3->text();
        QString heure_arrive=ui->lineEdit_5->text();
        int no_escale= ui->lineEdit_6->text().toInt();
        int num_billet=ui->lineEdit_01->text().toInt();
    vol v(num_vol,date_depart,date_arrive, heure_arrive,heure_depart,no_escale,num_billet);




    bool test=v.ajouter();
    if(test)
    {
       mysystem->showMessage(tr("Notification"),tr("ajout avec succes"));
        ui->tabvol->setModel(tmpvol.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un vol"),
                      QObject::tr("vol ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else if(!test)
    {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un vol"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

}

void MainWindow::on_pushButton_supp_clicked()
{int num_vol = ui->lineEdit_7->text().toInt();
    bool test=tmpvol.supprimer(num_vol);
    if(test)
    {mysystem->showMessage(tr("Notification"),tr("supprimer avec succes"));
        ui->tabvol->setModel(tmpvol.afficher());//refresh
        //QMessageBox::information(nullptr, QObject::tr("Supprimer un vol"),
                    //QObject::tr("vol supprimé.\n"
                                //"Click Cancel to exit."), QMessageBox::Cancel);

    //}
    //else if(!test)
    /*
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

}
}

void MainWindow::on_pushButton_modiv_clicked()
{
    int num_vol= ui->lineEdit_8->text().toInt();
        QString date_depart= ui->lineEdit_9->text();
        QString heure_depart=ui->lineEdit_11->text();
        QString date_arrive=ui->lineEdit_10->text();
        QString heure_arrive=ui->lineEdit_12->text();
        int no_escale= ui->lineEdit_13->text().toInt();
        int num_billet=ui->lineEdit_16->text().toInt();

         bool test=tmpvol. modifier( num_vol,date_depart,date_arrive,heure_arrive,heure_depart,no_escale,num_billet);
            if (test)
            {mysystem->showMessage(tr("Notification"),tr("modifier avec succes"));
                 ui->tabvol->setModel( tmpvol.afficher());

               // QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                     //       QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
            }
            /*else
                QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                            QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}*/
}


void MainWindow::on_pushButton_recherv_clicked()
{int num_vol;

    num_vol=ui->lineEdit_15->text().toInt();
bool test= true;
if(test==(true))
{
  ui->tabrech->setModel(tmpvol.Rechercher(num_vol));
//QMessageBox::information(nullptr, QObject::tr("vol existe  !"),
        //    QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}


/*(test==(false))
{
     ui->tabrech->setModel(tmpvol.Rechercher(num_vol));

    QMessageBox::information(nullptr, QObject::tr("vol n'existe pas"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}*/

}


void MainWindow::on_pushButton_ajouteres_clicked()
{    int no_escale= ui->lineEdit_14->text().toInt();
       int num_vol= ui->lineEdit_17->text().toInt();

         QString date_depart= ui->lineEdit_18->text();

              QString date_arrive=ui->lineEdit_19->text();



escale e(no_escale,num_vol,date_depart,date_arrive);
 bool test=e.ajouter();
 if(test)
 {
    mysystem->showMessage(tr("Notification"),tr("ajout avec succes"));
     ui->tabescale->setModel(tmpescale.afficher());//refresh

}
}

void MainWindow::on_pushButton_suppes_clicked()
{

 int no_escale = ui->lineEdit_24->text().toInt();
        bool test=tmpescale.supprimer(no_escale);
        if(test)
        {mysystem->showMessage(tr("Notification"),tr("supprimer avec succes"));
            ui->tabescale->setModel(tmpescale.afficher());//refresh
}
    }


void MainWindow::on_pushButton_reches_clicked()
{
    int no_escale;

        no_escale=ui->lineEdit_25->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabreche->setModel(tmpescale.rechercher(no_escale));
}
}



void MainWindow::on_pushButton_modes_clicked()
{int no_escale= ui->lineEdit_20->text().toInt();
    int num_vol= ui->lineEdit_21->text().toInt();

      QString date_depart= ui->lineEdit_22->text();

           QString date_arrive=ui->lineEdit_23->text();


    bool test=tmpescale. modifier( no_escale,num_vol,date_depart,date_arrive );
       if (test)
       {mysystem->showMessage(tr("Notification"),tr("modifier avec succes"));
            ui->tabescale->setModel( tmpescale.afficher());

}
}

void MainWindow::on_pushButton_tri_clicked()
{
     ui->tabvol->setModel( tmpvol.afficher_tri());
}



void MainWindow::on_pushButton_imprimer_clicked()
{
 QPrinter printer;
 printer.setPrinterName("print");
 QPrintDialog dialog(&printer,this);
 if (dialog.exec() ==QDialog::Rejected) return;
 ui->textEdit->print(&printer);
}

void MainWindow::on_pushButton_5_clicked()
{
    data=A.read_from_arduino();
    QString x=QString::fromStdString(data.toStdString());
    ui->label_38->setText(x) ;


}
