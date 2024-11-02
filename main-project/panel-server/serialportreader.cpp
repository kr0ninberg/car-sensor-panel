#include "serialportreader.h"
#include <QCoreApplication>
#include <QDebug>


SerialPortReader::SerialPortReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortReader::handleReadyRead);//когда что-то приходит на порт мы читаем
}

void SerialPortReader::handleReadyRead()
{

    // надо парсить по "\r\n"

    m_readData.clear();
    m_readData.append(m_serialPort->readAll());
    qDebug() << m_readData;

    QString ID;
    QString value;
    while(m_readData.contains("\r\n")){
        QByteArray data = m_readData.chopped(m_readData.size() - m_readData.indexOf("\r\n"));
        m_readData.remove(0, m_readData.indexOf("\r\n")+2);
        if(data.contains(' ')){
            ID = data.split(' ')[0];
            value = data.split(' ')[1];
        } else {
            ID = "all";
            value = data;
        }
        emit portOut(ID, value);
    }
};
