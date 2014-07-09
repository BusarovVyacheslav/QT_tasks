#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gun.h"
#include "shell.h"
#include "target.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mUi(new Ui::MainWindow)
    , mScene(new QGraphicsScene(this))
    , mShell(nullptr)
{
    mUi->setupUi(this);
    mUi->graphicsView->setScene(mScene); //создаём сцену
    mUi->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop); //размещаем сцену в верхнем левом углу
    mTimer = new QTimer(this); //timer
    mGun = new Gun();
    mScene->addItem(mGun);
    mTarget = new Target(mUi->spinBoxForTargetX->value(), mUi->spinBoxForTargetY->value(), mUi->spinBoxForRad->value());
    mScene->addItem(mTarget);

    connect(mUi->upButton, &QPushButton::clicked, this, &MainWindow::barrelDown);
    connect(mUi->downButton, &QPushButton::clicked, this, &MainWindow::barrelUp);
    connect(mUi->newGameButton, &QPushButton::clicked, this, &MainWindow::buildNewTarget);
    connect(mTimer, &QTimer::timeout, this, &MainWindow::updateTimer);
    connect(mUi->fireButton, &QPushButton::clicked, this, &MainWindow::fire);
}

void MainWindow::fire() {
    //случай повторного пуска
    if(mShellCreate) {
        clearState();
    }

    mTarget->newGame();
    mShellCreate = true;
    mShell = new Shell(mGun->currentGunBarrelPosition(), mGun->counterGunBarrelPosition(), mUi->powerScrollBar->value());
    mScene->addItem(mShell);
    mTimer->start(mInterval);
    mScene->invalidate();
}

qreal MainWindow::length(const QPointF &a, const QPointF &b) {
    return (sqrt( (a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()) ));
}

bool MainWindow::isShellOutOfRange() {
    return mShell->position().x() < -borgerOfGraphicsView
            || mShell->position().x() > mUi->graphicsView->width() + borgerOfGraphicsView
            || mShell->position().y() < -borgerOfGraphicsView
            || mShell->position().y() > mUi->graphicsView->height() + borgerOfGraphicsView;
}

void MainWindow::hitOrOut() {
    if (isShellOutOfRange()) {
        mShellOutOfRange = true;
        return;
    }

    QPointF shellCenter(mShell->position().x() + mShell->rad() / 2, mShell->position().y() + mShell->rad() / 2);
    QPointF targetCenter(mTarget->position().x() + mTarget->rad() / 2, mTarget->position().y() + mTarget->rad() / 2);

    if ((length(shellCenter, targetCenter) - mShell->rad() / 2) <= mTarget->rad() / 2) {
        mTarget->gotHit();
        mScene->invalidate();
    }
}

void MainWindow::updateTimer() {
    mShell->move();
    hitOrOut();
    mScene->invalidate();
    //если произошло попадание или выход из поля
    if (mTarget->isItHit() || mShellOutOfRange) {
        clearState();
    }
}

void MainWindow::clearState() {
    mShellCreate = false;
    delete mShell;
    mTimer->stop();
    mScene->invalidate();
    mShellOutOfRange = false;
}

void MainWindow::barrelDown() {
    mGun->changeCounter(1);
    mScene->invalidate();
}

void MainWindow::barrelUp() {
    mGun->changeCounter(-1);
    mScene->invalidate();
}

void MainWindow::buildNewTarget() {
    delete mTarget;
    mTarget = new Target(mUi->spinBoxForTargetX->value(), mUi->spinBoxForTargetY->value(), mUi->spinBoxForRad->value());
    mScene->addItem(mTarget);
    mScene->invalidate();
}

MainWindow::~MainWindow() {
    delete mUi;
}
