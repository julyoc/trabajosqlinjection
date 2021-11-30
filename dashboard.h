#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "user.h"

#include <QFrame>

namespace Ui {
class dashboard;
}

class dashboard : public QFrame
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();
    void setData(User usr);
private:
    Ui::dashboard *ui;

};

#endif // DASHBOARD_H
