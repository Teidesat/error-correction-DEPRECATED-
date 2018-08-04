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
            setBaudRate(QSerialPort::Baud115200);
            setParity(QSerialPort::NoParity);
            setStopBits(QSerialPort::OneStop);
            setFlowControl(QSerialPort::NoFlowControl);
            connected = true;
        }
    }
    return connected;
}

void Arduino::sendDataArduino(int data)
{
    if (connected && isWritable()) {
        QString str = QString::number(data) + "\n";
        write(str.toStdString().c_str());
    }
}

bool Arduino::isConnected() const
{
    return connected;
}
