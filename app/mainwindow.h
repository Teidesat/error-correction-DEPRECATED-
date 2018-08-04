#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    static const quint16 arduinoVendorId = 9025;
    static const quint16 arduinoModelId = 67;

    Ui::MainWindow *ui;
    QSerialPort *arduino;
    bool connected;

private:
    void disconnectArduino();
    bool connectArduino();
    void sendDataArduino(int data);
    void updateConnectButton();
    void sendValue();
};

#endif // MAINWINDOW_H
