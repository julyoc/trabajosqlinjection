#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "dashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->regBtn->setDisabled(true);
    ui->ingBtn->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ingBtn_clicked()
{
    auto usr = ui->Username->text();
    auto pass = ui->Password->text();
    auto user = User::findByUserName(usr);
    ui->regBtn->setDisabled(true);
    ui->ingBtn->setDisabled(true);
    if (user.password == pass) {
        this->ds.setData(user.copy());
        this->ds.show();
    }
}


void MainWindow::on_regBtn_clicked()
{
    auto usr = ui->Username->text();
    auto pass = ui->Password->text();
    auto user0 = User::findByUserName(usr);
    if (user0.userName == usr) {
        ui->message->setText("El usuario ya Existe.");
        ui->regBtn->setDisabled(true);
        ui->ingBtn->setDisabled(true);
        return;
    }
    auto user = User(usr, pass);
    user.save();
    ui->regBtn->setDisabled(true);
    ui->ingBtn->setDisabled(true);
}


void MainWindow::on_Username_textChanged(const QString &arg1)
{
    if (ui->Password->text().isEmpty()) return;
    if (
            ui->Username->text().contains("select") ||
            ui->Username->text().contains("SELECT") ||
            ui->Username->text().contains("insert") ||
            ui->Username->text().contains("INSERT") ||
            ui->Username->text().contains("drop") ||
            ui->Username->text().contains("DROP") ||
            ui->Password->text().contains("select") ||
            ui->Password->text().contains("SELECT") ||
            ui->Password->text().contains("insert") ||
            ui->Password->text().contains("INSERT") ||
            ui->Password->text().contains("drop") ||
            ui->Password->text().contains("DROP")
            ) {
        ui->regBtn->setDisabled(true);
        ui->ingBtn->setDisabled(true);
        return;
    }
    ui->regBtn->setDisabled(false);
    ui->ingBtn->setDisabled(false);
}


void MainWindow::on_Password_textChanged(const QString &arg1)
{
    if (ui->Username->text().isEmpty()) return;
    if (
            ui->Password->text().contains("select") ||
            ui->Password->text().contains("SELECT") ||
            ui->Password->text().contains("insert") ||
            ui->Password->text().contains("INSERT") ||
            ui->Password->text().contains("drop") ||
            ui->Password->text().contains("DROP") ||
            ui->Username->text().contains("select") ||
            ui->Username->text().contains("SELECT") ||
            ui->Username->text().contains("insert") ||
            ui->Username->text().contains("INSERT") ||
            ui->Username->text().contains("drop") ||
            ui->Username->text().contains("DROP")
            ) {
        ui->regBtn->setDisabled(true);
        ui->ingBtn->setDisabled(true);
        return;
    }
    ui->regBtn->setDisabled(false);
    ui->ingBtn->setDisabled(false);
}

