#include <QtCore>
#include <QtGui>

#include "target.h"


Target::Target(qreal x, qreal y, qreal r) : mCenter(x, y), mRad(r) {
}

QRectF Target::boundingRect() const {
     return QRectF(225, -30, 200, 200);
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(Qt::blue);
    painter->drawEllipse(mCenter.x(), mCenter.y(), mRad, mRad);
    if (mHit) {
        painter->setPen(Qt::red);
        painter->setFont(QFont("Arial", 40));
        painter->drawText(boundingRect(), Qt::AlignCenter, "BOOM!");
        painter->setBrush(Qt::red);
        painter->drawEllipse(mCenter.x(), mCenter.y(), mRad, mRad);
    }
}


QPointF Target::position() {
    return mCenter;
}

qreal Target::rad() {
    return mRad;
}

bool Target::isItHit() {
    return mHit;
}

void Target::gotHit() {
    mHit = true;
}

void Target::newGame() {
    mHit = false;
}

