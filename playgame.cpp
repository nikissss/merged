#include "playgame.h"
#include "ui_playgame.h"

playgame::playgame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playgame)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/nikki/OneDrive/Desktop/db/db.db");
}

playgame::~playgame()
{
    delete ui;
}
