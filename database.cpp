#include "database.h"

DataBase::DataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.sqlite");
    if (!db.open())
    {
        qDebug() << "***ERROR in DataBase(): Database not opened!";
    }
    query = QSqlQuery(db);
    // DDL query
    QString str = "CREATE TABLE IF NOT EXISTS credentials ("
                  "number INTEGER PRIMARY KEY NOT NULL, "
                  "name TEXT, "
                  "surname TEXT,"
                  "date_of_birth TEXT,"
                  "login TEXT,"
                  "password TEXT"
                  ");";
    bool b = query.exec(str);
    if (!b)
    {
        qDebug() << "Something went wrong! Table credentials not created! b="<<b
                 << query.lastError().isValid()
                 << query.lastError().text()
                 << query.lastError().number();
    }
    else
    {
        qDebug() << "Table credentials is created b="<<b
                 << " query.isValid()="
                 << query.isValid();
    }
}

bool DataBase::IsRegistered(QString login, QString password)
{
    query.clear();
    query.prepare("SELECT * FROM credentials WHERE login=? AND password=?;");
    query.bindValue(0, login);
    query.bindValue(1, password);
    bool b = query.exec();
    if (!b)
    {
        qDebug() << "Something went wrong! SELECT credentials does not work! b="<<b
                 << query.lastError().isValid()
                 << query.lastError().text()
                 << query.lastError().number();
    }
    else
    {
        qDebug() << "SELECT credentials works properly b="<<b
                 << " query.isValid()="
                 << query.isValid();

        if(query.value(0).toString() == login &&
                query.value(1).toString() == password)
            return true;

    }

    return false;
}

bool DataBase::RegisterCredentials(QString name, QString surname,
                                   QDate birthdate, QString login,
                                   QString password)
{
    //query.clear();
    query.prepare("INSERT INTO credentials (name, surname, date_of_birth, login, password) "
                  "VALUES (?, ?, ?, ?, ?);");

    query.bindValue(0, name);
    query.bindValue(1, surname);
    query.bindValue(2, birthdate);
    query.bindValue(3, login);
    query.bindValue(4, password);
    bool b = query.exec();
    if (!b)
    {
        qDebug() << "Something went wrong! RegisterCredentials() does not work! b="<<b
                 << query.lastError().isValid()
                 << query.lastError().text()
                 << query.lastError().number();
        return false;
    }
    else
    {
        qDebug() << "RegisterCredentials() works properly b="<<b
                 << " query.isValid()="
                 << query.isValid();
        return true;

    }
}

bool DataBase::FindNameAndSurnameAmongUsers(QString name, QString surname)
{
    static int CALL=0;
    //check if already registered:
    //query.clear();
    query.prepare("SELECT COUNT(*) FROM credentials WHERE name=? AND surname=?;");
    query.bindValue(0, name);
    query.bindValue(1, surname);
    bool b = query.exec();
    if (!b)
    {
        qDebug() << "Something went wrong! SELECT COUNT(*) in FindNameAndSurnameAmongUsers() does not work! b="<<b
                 << query.lastError().isValid()
                 << query.lastError().text()
                 << query.lastError().number();
        return false;
    }
    else
    {
        qDebug() << "SELECT COUNT(*) in FindNameAndSurnameAmongUsers() works properly b="<<b
                 << " query.isValid()="
                 << query.isValid();
    }
    int count=0;
    if (query.next()) {
        count = query.value(0).toInt();
    } else {
        qDebug() << query.lastError(); //check your error here
    }

    qDebug() << "count=" << count <<" CALL=" << CALL;
    ++CALL;

    if(count) return true;
    else      return false;
}
