#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>

#include <QDebug>
#include <QDate>
#include <QMessageBox>

#include <QSqlQueryModel>
#include <QTableView>

class DataBase {

public:
    DataBase();
    ~DataBase()
    {
        db.close();
    }
    bool IsRegistered(QString login, QString password);
    bool RegisterCredentials(QString name, QString surname,
                             QDate birthdate, QString login,
                             QString password);
    bool FindNameAndSurnameAmongUsers(QString name, QString surname);

private:

public:
    QSqlQuery query;
    QSqlRecord record;
    QSqlDatabase db;
};

#endif // DATABASE_H
