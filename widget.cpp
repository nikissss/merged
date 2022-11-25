#include "widget.h"
#include "ui_widget.h"
#include<scene.h>
#include<birditem.h>
#include<mainwindow.h>
#include <QGraphicsPixmapItem>
/*#include "playgame.h"
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
}*/
//MainWindow *mainw;

widget::widget(QWidget *parent) :
     QDialog(parent)
   , ui(new Ui::widget)
{
    ui->setupUi(this);
     this->setFixedSize(728,518);

    scene = new Scene(this);
    scene->setSceneRect(-250,-280,480,580);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/background5.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2,
                                           pixItem->boundingRect().height()/2));
    scene->addLine(-400,0,400,0,QPen(Qt::blue));
    scene->addLine(0,-400,0,400,QPen(Qt::blue));

    // PillarItem * pillar = new PillarItem();
     //scene->addItem(pillar);

 // BirdItem * bird = new BirdItem(QPixmap(":/image/birdupp.png"));
   // scene()->addItem(bird);

     //ui->startGameButton->setScene(scene);
     scene->addBird();


}



/*
void Widget::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
   db.setDatabaseName("/Users/pujakadayat/Desktop/flap.db");

    if(db.open()){
        QMessageBox::information (this, "Connection","Database connected successfully");
    }
    else{
        QMessageBox::information(this,"not connected", "Database not connected");
    }

}


void Widget::on_pushButton_2_clicked()
{

}

*/
void widget::on_startGameButton_clicked()
{
   scene->startGame();
}

widget::~widget()
{
    delete ui;
}
