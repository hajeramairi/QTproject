#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    connection c;

  bool test=c.ouvrirconnect();
  MainWindow w;
  if(test)
  {w.show();

      QMessageBox::critical(nullptr, QObject::tr("database is  open"),
                  QObject::tr("connection avec succés.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();}


