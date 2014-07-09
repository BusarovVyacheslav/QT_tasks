#include <QTransform>

#include "mainwindow.h"
#include "gun.h"


Gun::Gun() {
}

QRectF Gun::boundingRect() const {
    return QRectF(0, 0, 300, 300);
}

void Gun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawEllipse(5, 300, 90, 90);
    painter->translate(50, 340);
    painter->rotate(mCurrentAngleGuns * mAngleCounter);
    painter->drawRect(50, 0, 80, 10);
}

void Gun::changeCounter(qreal value) {
    if (value == 1)
        mAngleCounter++;

    if (value == -1)
        mAngleCounter--;
}

qreal Gun::currentGunBarrelPosition() {
    return mCurrentAngleGuns;
}

qreal Gun::counterGunBarrelPosition() {
    return mAngleCounter;
}
