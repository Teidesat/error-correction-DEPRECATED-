#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QPushButton>

class Arduino : public QSerialPort
{
private:
    static const quint16 arduinoVendorId = 6790; // 9025
    static const quint16 arduinoModelId = 29987; // 67
    bool connected;

public:

    Arduino();
    void disconnectArduino();
    bool connectArduino();
    void sendDataArduino(char data);
    bool isConnected() const;
};

#endif // ARDUINO_H
