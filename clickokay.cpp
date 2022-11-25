#include "clickokay.h"
#include "ui_clickokay.h"
#include "mainwindow.h"

MainWindow *mainw;

clickokay::clickokay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clickokay)
{
    ui->setupUi(this);
}

clickokay::~clickokay()
{
    delete ui;
}


void clickokay::on_dialogButtonBox_accepted()
{
    mainw = new MainWindow;
    mainw->show();
}

