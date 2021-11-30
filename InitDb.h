#ifndef INITDB_H
#define INITDB_H

#include <QtSql>

const auto CREATE_USER_TABLE = QString("CREATE TABLE IF NOT EXISTS users ("
                                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                       "username VARCHAR NOT NULL,"
                                       "password VARCHAR NOT NULL"
                                       ");");

//const auto CREATE_FINDBYID_PROCEDURE

QSqlDatabase initDb(QString connecturi) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(connecturi);
    return db;
}

#endif // INITDB_H
