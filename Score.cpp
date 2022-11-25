#include "Score.h"
#include "QtWidgets/qgraphicsitem.h"
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
//initialize  the score to 0
    score = 0;
    //draw the text
    setPlainText("Score:" + QString::number(score));
}
