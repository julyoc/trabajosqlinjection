#ifndef CONNECTDB_H
#define CONNECTDB_H

#include <QObject>
#include <QtSql>

class ConnectDb : public QObject
{
    Q_OBJECT
public:
    explicit ConnectDb(QObject *parent = nullptr);
    bool openConnection();
    void closeConnection();
    QString getErrStr();
private:
    QSqlDatabase db;
    QSqlError err;
    void initializedb();

signals:

};

#endif // CONNECTDB_H
