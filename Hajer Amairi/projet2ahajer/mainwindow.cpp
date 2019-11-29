#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog_client.h"
#include"dialog_carte.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Dialog_client dialog_client;
       dialog_client.setModal(true);
       dialog_client.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog_carte dialog_carte;
       dialog_carte.setModal(true);
       dialog_carte.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}


