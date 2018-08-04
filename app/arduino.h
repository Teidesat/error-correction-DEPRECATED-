#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QPushButton>

class Arduino : public QSerialPort
{
public:
    Arduino();

private:
    static const quint16 arduinoVendorId = 9025;
    static const quint16 arduinoModelId = 67;
    bool connected;

public:
    void disconnectArduino();
    bool connectArduino();
    void sendDataArduino(int data);
    bool isConnected() const;
};

#endif // ARDUINO_H
