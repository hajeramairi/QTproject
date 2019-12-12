#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vol.h"
#include "escale.h"
#include<QSystemTrayIcon>
#include <QMainWindow>
#include "arduino.h"

namespace Ui {
class MainWindow;
}
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void readSerial();
    void updateTemperature(QString);
    void update_label() ;
    //void on_pb_supprimer_clicked();

    void on_pushButton_ajouterv_clicked();

    void on_pushButton_supp_clicked();

    void on_pushButton_modiv_clicked();

    void on_pushButton_recherv_clicked();


    void on_pushButton_ajouteres_clicked();

    void on_pushButton_suppes_clicked();

    void on_pushButton_reches_clicked();


    void on_pushButton_modes_clicked();

    void on_pushButton_tri_clicked();



    void on_pushButton_imprimer_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    vol tmpvol;
    escale tmpescale;
    vol tmprech;
    escale tmpreche;
    QSystemTrayIcon * mysystem;
 Arduino A;
 QByteArray data;


};

#endif // MAINWINDOW_H
