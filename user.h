#ifndef USER_H
#define USER_H

#include <QObject>
#include <QtSql>

const auto ADDUSERS_SQLSCRIPT = QString("INSERT INTO users (username, password) VALUES (?, ?);");

const auto GETUSERBYID_SQLSCRIPT = QString("SELECT * FROM users WHERE users.id == ?");

const auto GETUSERBYUSERNAME_SQLSCRIPT = QString("SELECT * FROM users WHERE users.username == ?");

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    explicit User(QString usr, QObject *parent = nullptr);
    explicit User(QString usr, QString pass, QObject *parent = nullptr);
    explicit User(QVariant idd, QString usr, QString pass, QObject *parent = nullptr);
    QString userName;
    QString password;
    QVariant id;

    QSqlError save();
    static User findById(qint32 id);
    static User findByUserName(QString username);
    User copy();

private:
    QSqlQuery q;

signals:

};

#endif // USER_H
