#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dashboard.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_ingBtn_clicked();

    void on_regBtn_clicked();

    void on_Username_textChanged(const QString &arg1);

    void on_Password_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    dashboard ds;
};
#endif // MAINWINDOW_H
