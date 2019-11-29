#include "mainwindow.h"

#include <QApplication>
#include<QtSql>
#include<QtDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("hajer");
    db.setUserName("hajer");
    db.setPassword("hajer");
    if (db.open())
    {
        qDebug()<<"data base open";
    }
    else
    {
        qDebug()<<"data base closed or there is an error";
    }

    return a.exec();
}
