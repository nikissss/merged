#include "birditem.h"
#include <QTimer>
#include <QGraphicsScene>

BirdItem::BirdItem(const QPixmap &pixmap)  :
    wingPosition(WingPosition::Up),
    wingDirection(0)
{
    setPixmap(pixmap);

    QTimer * birdWingsTimer = new QTimer(this);
    connect(birdWingsTimer, &QTimer::timeout,[=](){
        updatePixmap();
    });

    birdWingsTimer->start(100);
    groundPosition = scenePos().y() + 350;

    yAnimation = new QPropertyAnimation(this,"y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation ->setDuration(1000);
  //  yAnimation->start();
    rotationAnimation = new QPropertyAnimation(this,"rotation",this); //rotationanimation to rotata bird as it moves down
   // rotateTo(90,1200,QEasingCurve::InQuad);

}
qreal BirdItem::rotation() const
{
    return m_rotation;

}

qreal BirdItem::y() const
{
    return m_y;
}

void BirdItem::shootUp()
{
    yAnimation->stop(); //yanimation to move bird down
    rotationAnimation->stop();
    qreal curPosY= y();

    yAnimation->setStartValue(curPosY);
    yAnimation->setEndValue(curPosY - scene()->sceneRect().height()/8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);
    yAnimation->start();
    connect(yAnimation,&QPropertyAnimation::finished,[=](){
        fallToGroundIfNecessary();

    });
yAnimation->start();
    rotateTo(-20,200,QEasingCurve::OutCubic);
}

void BirdItem::startFlying()
{
    yAnimation->start();
    rotateTo(90,1200,QEasingCurve::InQuad);
}
void BirdItem::stopFlying()
{
    yAnimation->stop();
    rotationAnimation->stop();
}

void BirdItem::setRotation(qreal rotation)
{
    m_rotation  = rotation;

    QPointF c = boundingRect().center();

    QTransform t;
    t.translate(c.x(),c.y());
    t.rotate(rotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);
}

void BirdItem::setY(qreal y)  //setter for yproperty animation
{
    moveBy(0,y-m_y);
    m_y = y;
}
void BirdItem::buildAnimation()
{
    yAnimation = new QPropertyAnimation(this,"y", this);
    yAnimation->setStartValue(scenePos().y()-50);

    yAnimation->setEndValue(groundPosition);
      yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1200);
 rotationAnimation  = new QPropertyAnimation(this, "y", this);

};
void BirdItem::rotateTo(const qreal &end, const int &duration, const QEasingCurve &easingCurve)
{
    rotationAnimation ->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(easingCurve);
    rotationAnimation->setDuration(duration);
    rotationAnimation->start();
}

void BirdItem::fallToGroundIfNecessary()
{
    if (y() < groundPosition){

        rotationAnimation->stop();
        yAnimation->stop();
        yAnimation->setStartValue(y());
        yAnimation->setEasingCurve(QEasingCurve::InQuad);
        yAnimation->setEndValue(groundPosition);
        yAnimation->setDuration(1200);
        yAnimation->start();

        rotateTo(90,1100,QEasingCurve::InCubic);
    }
}

void BirdItem::updatePixmap()
{
    if(wingPosition == WingPosition::Middle){

        if(wingDirection) {
            //UP
            setPixmap(QPixmap(":/images/315272049_454336400081540_3041457456825348632_n.png"));
            wingPosition  = WingPosition::Up;
            wingDirection = 0;
        }else{
            //Down
            //Up
            setPixmap(QPixmap(":/images/315272049_454336400081540_3041457456825348632_n.png"));
            wingPosition = WingPosition::Down;
            wingDirection= 1;
        }
    }else{
        setPixmap(QPixmap(":/images/315272049_454336400081540_3041457456825348632_n.png"));
        wingPosition=WingPosition::Middle;
    }
}




