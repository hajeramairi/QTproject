#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personnel.h"
#include "departement.h"
#include "widgett.h"
#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QImage>
#include <QFileDialog>
#include <QSound>
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots :
    void openWidgett();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();
    void on_pb_ajouter_2_clicked();
    void on_pb_supprimer_2_clicked();
    void on_modifierr_clicked();
    void on_upload_clicked();

    void on_quit_clicked();

    void on_chercher_clicked();

    //void on_bb_clicked();

private:
    Ui::MainWindow *ui;
    QSound *son;
    QPropertyAnimation *animation;
    Personnel  tmppersonnel;
    Departement tmpdepartement;
    Widgett *myWidgett;
};

#endif // MAINWINDOW_H
