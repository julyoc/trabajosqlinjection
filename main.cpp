#include "mainwindow.h"

#include <QApplication>
#include <QtSql>
#include "connectdb.h"

int main(int argc, char *argv[])
{
    ConnectDb ddbb = ConnectDb();
    ddbb.openConnection();
    QTextStream(stdout) << ddbb.getErrStr() << "\n";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
