#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMainWindow>

#include "gun.h"
#include "target.h"
#include "shell.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void barrelDown();
    void barrelUp();
    void fire();
    void updateTimer();
    void hitOrOut();
    void buildNewTarget();

private:
    qreal length(QPointF const &a, QPointF const &b);
    Ui::MainWindow *mUi;
    QGraphicsScene *mScene;
    QTimer *mTimer;
    Gun *mGun;
    Target *mTarget;
    Shell *mShell;
    bool mShellOutOfRange = false;
    bool mShellCreate = false;
    qreal const mInterval = 50;
    int const borgerOfGraphicsView = 2000;

    void clearState();
    bool isShellOutOfRange();


};


