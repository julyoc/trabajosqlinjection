#include "dashboard.h"
#include "ui_dashboard.h"

dashboard::dashboard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
}

void dashboard::setData(User usr) {
    ui->id->insert(usr.id.toString());
    ui->usr->insert(usr.userName);
    ui->pass->insert(usr.password);
}

dashboard::~dashboard()
{
    delete ui;
}
