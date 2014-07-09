#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Shell : public QGraphicsItem
{
public:
    Shell(qreal x, qreal y, qreal speed);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void move();
    QPointF position();
    qreal rad();

private:
    qreal mShift;
    qreal mTurn;
    QPointF mCoordinate;
    qreal mSpeed = 0;
    QPointF mGravityVector;
    QPointF const mF = {0, 1}; //vertor of gravity
};
