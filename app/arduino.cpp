#include "arduino.h"

Arduino::Arduino()
    : QSerialPort()
    , connected(false)
{}

void Arduino::disconnectArduino()
{
    disconnect();
    close();
    connected = false;
}

bool Arduino::connectArduino()
{
    connected = false;
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasVendorIdentifier() && (serialPortInfo.productIdentifier() == arduinoModelId)){
            qDebug() << "Arduino found!" << serialPortInfo.productIdentifier() << "at" << serialPortInfo.portName();
            setPortName(serialPortInfo.portName());
            open(QIODevice::ReadWrite);
            setDataBits(QSerialPort::Data8);
            setBaudRate(2000000);
            setParity(QSerialPort::NoParity);
            setStopBits(QSerialPort::OneStop);
            setFlowControl(QSerialPort::NoFlowControl);
            connected = true;
        }
    }
    return connected;
}

void Arduino::sendDataArduino(char data)
{
    if (connected && isWritable()) {
        qDebug() << data;
        const char buffer[2] = { data, '\0' };
        write(buffer);
    }
}

bool Arduino::isConnected() const
{
    return connected;
}
