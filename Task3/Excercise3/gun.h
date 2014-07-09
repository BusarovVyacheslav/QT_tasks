#pragma once

#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Gun : public QGraphicsItem
{
public:
    Gun();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void changeCounter(qreal value);
    qreal currentGunBarrelPosition(); //для вылета снаряда
    qreal counterGunBarrelPosition();


private:
    qreal const mCurrentAngleGuns = -3;
    qreal mAngleCounter = 0;

};
