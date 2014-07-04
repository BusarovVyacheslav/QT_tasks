#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtWebKit>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //источник, указатель на метод источник(сигнал), приёмник, слот - приёмник
    connect (ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::onLineEditReturnPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLineEditReturnPressed() {
    QString urltogo = ui->lineEdit->text();
    QUrl url(urltogo);
    ui->webView->load(url);
}
