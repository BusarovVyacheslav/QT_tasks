#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Target : public QGraphicsItem
{
public:
    Target(qreal x, qreal y, qreal r);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPointF position();
    qreal rad();
    void gotHit();
    bool isItHit();
    void newGame();

private:
    qreal mRad;
    QPointF mCenter;
    bool mHit = false;
};
