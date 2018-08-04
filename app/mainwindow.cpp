#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , arduino(new Arduino)
{
    ui->setupUi(this);

    connect(ui->connectionBtn, &QPushButton::clicked, this, &MainWindow::updateConnectButton);
    connect(ui->sendValueBtn,  &QPushButton::clicked, this, &MainWindow::sendValue);
}

MainWindow::~MainWindow()
{
    arduino->disconnectArduino();
    delete ui;
    delete arduino;
}

void MainWindow::updateConnectButton()
{
    if (arduino->isConnected()) {
        arduino->close();
        ui->sendValueBtn->setEnabled(false);
        ui->connectionBtn->setText("Connect");
    } else if (arduino->connectArduino()) {
        ui->sendValueBtn->setEnabled(true);
        ui->connectionBtn->setText("Disconnect");
    }
}

void MainWindow::sendValue()
{
    arduino->sendDataArduino(ui->value->value());
}
