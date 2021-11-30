#include "user.h"


#include <QtSql>


User::User(QObject *parent) : QObject(parent)
{

}

User::User(QString usr, QObject *parent) : QObject(parent)
{
    this->userName = usr;
}

User::User(QString usr, QString pass, QObject *parent) : QObject(parent)
{
    this->password = pass;
    this->userName = usr;
}

User::User(QVariant idd, QString usr, QString pass, QObject *parent) : QObject(parent)
{
    this->password = pass;
    this->userName = usr;
    this->id = idd;
}

QSqlError User::save() {
    if (!this->q.prepare(ADDUSERS_SQLSCRIPT)) return this->q.lastError();
    q.addBindValue(this->userName);
    q.addBindValue(this->password);
    q.exec();
    this->id = q.lastInsertId();
    return this->q.lastError();
}

User User::copy() {
    return User(this->id, this->userName, this->password);
}

User User::findById(qint32 id) {
    QSqlQuery q;
    if (!q.prepare(GETUSERBYID_SQLSCRIPT)) QT_THROW(q.lastError());
    q.addBindValue(id);
    q.exec();
    auto usr = User();
    while (q.next()) {
        usr.id = q.value(0).toInt();
        usr.userName = QString(q.value(1).toString());
        usr.password = QString(q.value(2).toString());
    }
    return usr.copy();
}

User User::findByUserName(QString username) {
    QSqlQuery q;
    if (!q.prepare(GETUSERBYUSERNAME_SQLSCRIPT)) QT_THROW(q.lastError());
    q.addBindValue(username);
    q.exec();
    auto usr = User();
    while (q.next()) {
        usr.id = q.value(0).toInt();
        usr.userName = QString(q.value(1).toString());
        usr.password = QString(q.value(2).toString());
    }
    return usr.copy();
}
