#ifndef DIALOG_CARTE_H
#define DIALOG_CARTE_H
#include "stati.h"
#include <QDialog>
#include "carte_fid.h"
#include <QSystemTrayIcon>
namespace Ui {
class Dialog_carte;
}
class QSystemTrayIcon;

class Dialog_carte : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_carte(QWidget *parent = nullptr);
    ~Dialog_carte();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_tablecarte_2_currentChanged(int index);

    void on_showmessagepuchbutton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog_carte *ui;
    carte_fid tempfid;
    QSystemTrayIcon *mysystemTrayIcon;
stati * sta;

};

#endif // DIALOG_CARTE_H
