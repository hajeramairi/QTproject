#ifndef DIALOG_CLIENT_H
#define DIALOG_CLIENT_H

#include <QDialog>
#include"client.h"
namespace Ui {
class Dialog_client;
}
class QSystemTrayIcon;

class Dialog_client : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_client(QWidget *parent = nullptr);
    ~Dialog_client();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_showmessagepushbutton_clicked();

private:
    Ui::Dialog_client *ui;
    client tempclient;
    QSystemTrayIcon *mysystemTrayIcon;
};

#endif // DIALOG_CLIENT_H
