#ifndef SCENE_H
#define SCENE_H
//#include <QGraphicsScene>
//#include <QTimer>
#include "birditem.h"
#include "pillaritem.h"
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
//#include <QTimer>
//#include "pillaritem.h"

//#include "birditem.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void addBird();
        //void startGame();
    bool isGameOn() const;
    int getScore() const;
    void setGameOn(bool isGameOn);
    void incrementScore();

signals:

public slots:
    // QGraphicsScene interface
    void startGame();
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:

    void showGameOverGraphics();
    void hideGameOvergraphics();
    void cleanPillars();
    void setUpPillarTimer();
    void freezeBirdAndPillarsInPlace();
    QTimer * pillarTimer;
    BirdItem * bird;

    bool gameOn;

    int score=0;
    int bestscore;


    QGraphicsPixmapItem * gameOverPix;
    QGraphicsTextItem * scoreTextItem;



};

#endif // SCENE_H
