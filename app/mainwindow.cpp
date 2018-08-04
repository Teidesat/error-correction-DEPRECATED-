#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , arduino(new QSerialPort)
    , connected(false)
{
    ui->setupUi(this);

    connect(ui->connectionBtn, &QPushButton::clicked, this, &MainWindow::updateConnectButton);
    connect(ui->sendValueBtn,  &QPushButton::clicked, this, &MainWindow::sendValue);
}

MainWindow::~MainWindow()
{
    disconnectArduino();
    delete ui;
    delete arduino;
}

void MainWindow::disconnectArduino()
{
    arduino->disconnect();
    arduino->close();
    connected = false;
}

bool MainWindow::connectArduino()
{
    connected = false;
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasVendorIdentifier() && (serialPortInfo.productIdentifier() == arduinoModelId)){
            qDebug() << "Arduino found!" << serialPortInfo.productIdentifier() << "at" << serialPortInfo.portName();
            arduino ->setPortName(serialPortInfo.portName());
            arduino->open(QIODevice::ReadWrite);
            arduino->setDataBits(QSerialPort::Data8);
            arduino ->setBaudRate(QSerialPort::Baud115200);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            connected = true;
        }
    }
    return connected;
}

void MainWindow::sendDataArduino(int data)
{
    if (connected && arduino->isWritable()) {
        QString str = QString::number(data) + "\n";
        arduino->write(str.toStdString().c_str());
    }
}

void MainWindow::updateConnectButton()
{
    if (connected) {
        arduino->close();
        ui->sendValueBtn->setEnabled(false);
        ui->connectionBtn->setText("Connect");
    } else if (connectArduino()) {
        ui->sendValueBtn->setEnabled(true);
        ui->connectionBtn->setText("Disconnect");
    }
}

void MainWindow::sendValue()
{
    sendDataArduino(ui->value->value());
}
