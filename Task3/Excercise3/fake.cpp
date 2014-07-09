#include "fake.h"
#include <QDebug>

#include <QtCore>
#include <QtGui>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>


Fake::Fake(QPointF center) {
    this->center = center;
}

QRectF Fake::boundingRect() const {
    return QRectF(10, 30, 50, 20);
}

void Fake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::black);
    painter->drawEllipse(center.x(), center.y(), 5, 5);
}


