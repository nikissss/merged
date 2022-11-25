#ifndef PILLARITEM_H
#define PILLARITEM_H

#include "scene.h"
#include "birditem.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsItemGroup>
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>



class PillarItem : public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX )
public:
    explicit PillarItem();
    ~PillarItem();
    //PillarItem(QGraphicsPixmapItem *topPillar, QGraphicsPixmapItem *bottomPillar);
    qreal x() const;
    void stopPillar();

//signals:
    //void collidefail();
public slots:
    void  setX(qreal x);

private:
    bool isAfterBird = false;
qreal m_x;
int yPos;
    bool collidesWithBird() const;
    QGraphicsPixmapItem * topPillar;
    QGraphicsPixmapItem * bottomPillar;
    QPropertyAnimation * xAnimation;
    void buildAnimation();
   // int yPos;
    //qreal m_x;
    //bool pastBird;

signals:
    void collidefail();
};

#endif // PILLARITEM_H
