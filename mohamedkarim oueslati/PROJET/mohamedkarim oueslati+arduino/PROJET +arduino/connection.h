#ifndef CONNECTION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connection
{
private:
    QSqlDatabase db;
public:
    connection();
    bool ouvrirconnect();
    void fermerconnect();

};

#endif // CONNECTION_H
