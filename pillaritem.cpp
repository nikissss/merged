#include <pillaritem.h>
#include <QRandomGenerator>
#include <QGraphicsScene>//'#include "scene.h"
#include "birditem.h"
#include "scene.h"
#include <QDebug>

PillarItem::PillarItem():
    isAfterBird(false),
    topPillar(new QGraphicsPixmapItem(QPixmap(":/images/pillarup.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/images/pillardown.png")))
{

    topPillar-> setPos(QPointF(0,0) - QPointF(topPillar->boundingRect().width()/2,
                                              topPillar -> boundingRect().height()+ 60));
    bottomPillar->setPos(QPointF(0,0) + QPointF(-bottomPillar->boundingRect().width()/2,
                                                60));
    addToGroup(topPillar);
    addToGroup(bottomPillar);
    buildAnimation();
}
void PillarItem::buildAnimation()
{
    yPos =  QRandomGenerator::global()->bounded(150);
    int xRandomizer  = QRandomGenerator::global()-> bounded(200);

    setPos(QPoint(0,0) + QPoint(250 + xRandomizer, yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation-> setStartValue(250 + xRandomizer);
    xAnimation->setEndValue(-250);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500);

    connect (xAnimation, &QPropertyAnimation::finished,[=](){
        qDebug()<< "Animation finished";
        scene() -> removeItem(this);
        delete this;
    });
    xAnimation->start();
}
//PillarItem::~PillarItem(){

   // qDebug() << "Deleting pillar";
    //delete topPillar;
    //delete bottomPillar;
//}
qreal PillarItem::x() const
{
    return m_x;

}
//void PillarItem::stopPillar()
//{
   // xAnimation->stop();

//}
void PillarItem::setX(qreal x)
{
    qDebug() << "Pillar position: "<< x;
    m_x = x;

    if(x< 0 && !isAfterBird){
        isAfterBird = true;
        QGraphicsScene * mScene= scene();
        Scene * myScene = dynamic_cast<Scene *>(mScene);
        if(myScene){
            myScene->incrementScore();
        }
    }
    if(collidesWithBird()){
        emit collidefail();
    }
    setPos(QPointF(0,0) + QPointF(x,yPos));
}

bool PillarItem::collidesWithBird() const
{
    QList<QGraphicsItem*> collidingItems = topPillar->collidingItems();
    collidingItems.append(bottomPillar->collidingItems());
    foreach (QGraphicsItem * Item, collidingItems){
        BirdItem * birdItem = dynamic_cast<BirdItem*>(Item);
        if(birdItem){
            return true;
        }
    }
    return false;
}void PillarItem::stopPillar()
{
    xAnimation->stop();
}
    PillarItem::~PillarItem()
    {
        qDebug() << "Deleting pillar";
        delete topPillar;
        delete bottomPillar;
}

//PillarItem::PillarItem(QGraphicsPixmapItem *topPillar, QGraphicsPixmapItem *bottomPillar) : topPillar(topPillar),
//bottomPillar(bottomPillar)
