#include "shell.h"
#include <QDebug>


QRectF Shell::boundingRect() const {
    return QRectF(10, 30, 50, 20);
}

void Shell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawEllipse(mCoordinate.x(), mCoordinate.y(), rad(), rad());
}

void Shell::move() {
    mGravityVector += mF; //work force of gravity
    mCoordinate.setX(mCoordinate.x() + mGravityVector.x());
    mCoordinate.setY(mCoordinate.y() + mGravityVector.y());
}

QPointF Shell::position() {
    return mCoordinate;
}

qreal Shell::rad() {
    return 15;
}

Shell::Shell(qreal x, qreal y, qreal speed) : mShift(x), mTurn(y) {
    mCoordinate.setX(mCoordinate.x() + 130); //задание текущих кооржинат на старт
    mCoordinate.setY(mCoordinate.y());

    //после преобразований цель и снаряд остаются в одной системе координат
    QTransform transform; //преобразование системы координат
    transform.translate(50, 340); //чтобы снаряд вылетал из ствола
    transform.rotate(mShift * mTurn - 3); // поворот системы координат, чтобы снаряд летел по пораболе

    mCoordinate = transform.map(mCoordinate);
    mGravityVector.setX(mGravityVector.x() + speed); //влияние силы тяжести в зависимости от начальной скорости снаряда
    mGravityVector.setY(mGravityVector.y());

    QTransform transform1;
    transform1.rotate(mShift * mTurn - 3);
    mGravityVector = transform1.map(mGravityVector);
}

