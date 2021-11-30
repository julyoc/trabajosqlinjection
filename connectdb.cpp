#include "connectdb.h"
#include "InitDb.h"

#include <QtSql>
#include <iostream>

ConnectDb::ConnectDb(QObject *parent) : QObject(parent)
{
    this->db = initDb("../db.sqlite3");
    if (this->db.open()) {
        this->err = db.lastError();
    }
    QTextStream(stdout) << this->err.text() << "\n";
}

bool ConnectDb::openConnection() {
    bool op =  this->db.open();
    if (!op) this->err = this->db.lastError();
    else this->initializedb();
    return op;
}

void ConnectDb::closeConnection() {
    this->db.close();
}

void ConnectDb::initializedb() {
    QStringList tables = this->db.tables();
    if (tables.contains("users")) {
        this->err = QSqlError("Table exists");
        return;
    }
}

QString ConnectDb::getErrStr() {
    return this->err.text();
}
