#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Fake : public QGraphicsItem
{
public:
    Fake(QPointF center);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPointF center;
};
