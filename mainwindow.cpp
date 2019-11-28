#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_widgett.h"
#include "personnel.h"
#include "departement.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include "widgett.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
    QPixmap pixmap;
    QPixmap pix("C:/avio.png");
    ui->pic->setPixmap(pix);
   // connect(bb, SIGNAL(click()), this, SLOT(openWidgett()));
animation = new QPropertyAnimation(ui->bien, "geometry");
animation->setDuration(10000);
animation->setStartValue(ui->bien->geometry());
animation->setEndValue(QRect(200, 200, 0, 0));
animation->start();
son=new QSound(":/sound/son1.wav");
ui->tabetudiant->setModel(tmppersonnel.afficher());

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int NumP = ui->lineEdit_id->text().toInt();
    QString Nom= ui->lineEdit_nom->text();
    QString Fonction= ui->lineEdit_prenom->text();
    int Salaire = ui->lineEdit_Salaire->text().toInt();
    int Chef = ui->lineEdit_Chef->text().toInt();
    son->play();
  Personnel p(NumP,Nom,Fonction,Salaire,Chef);
  bool test=p.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmppersonnel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Personnel"),
                  QObject::tr("Personnel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int NumPP = ui->lineEdit_id_2->text().toInt();
bool test=tmppersonnel.supprimer(NumPP);
son->play();

if(test)
{ui->tabetudiant->setModel(tmppersonnel.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un Personnel"),
                QObject::tr("Personnel supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un Personnel"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_ajouter_2_clicked()
{
    int NumDep = ui->lineEdit_id_3->text().toInt();
    QString Emplacement= ui->lineEdit_nom_2->text();
    int NbrP = ui->lineEdit_prenom_2->text().toInt();
    son->play();

  Departement d(NumDep,Emplacement,NbrP);
  bool test=d.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpdepartement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Departement"),
                  QObject::tr("Departement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Departement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_2_clicked()
{
int NumDep = ui->lineEdit_id_4->text().toInt();
son->play();

bool test=tmpdepartement.supprimer(NumDep);
if(test)
{ui->tabetudiant->setModel(tmpdepartement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un Departement"),
                QObject::tr("Departement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un Departement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifierr_clicked()
{
    int NumPP = ui->lineEdit_Fonction->text().toInt();
    int SalaireN= ui->lineEdit_salaire->text().toInt();
    son->play();
    bool test=tmppersonnel.modifier(NumPP,SalaireN);
    if(test)
{
        ui->tabetudiant->setModel(tmppersonnel.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un Personnel"),
        QObject::tr("Personnel Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Personnel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_upload_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("images(*.png *.jpg *.jpeg)"));

 if (QString::compare(filename, QString()) != 0)
 {
       QImage image;
       bool valid=image.load(filename);
            if (valid)
    {
     ui->uploaded->setPixmap(QPixmap::fromImage(image));
    }
            else
    {
     QMessageBox::critical(nullptr, QObject::tr("CC"),
     QObject::tr("Erreur !.\n"
     "Click Cancel to exit."), QMessageBox::Cancel);
    }
 }

}
void MainWindow::on_chercher_clicked()
{
    int NumPP ;
    NumPP = ui->chercher1->text().toInt();
    son->play();
    QString res= QString::number(NumPP);
    bool test=true;
  if(test==(true))

{
      ui->tabetudiant_4->setModel(tmppersonnel.chercher(NumPP));//refresh
QMessageBox::information(nullptr, QObject::tr("Afficher un personnel"),
                  QObject::tr("Affichage complet.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("CC"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_quit_clicked()
{
    close();
    son->play();

}

void MainWindow::openWidgett()
{
   myWidgett = new Widgett(); // Be sure to destroy your window somewhere
   myWidgett->show();
   // ...
}
