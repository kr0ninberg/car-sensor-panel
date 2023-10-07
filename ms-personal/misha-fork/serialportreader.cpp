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

    m_readData.clear();
    m_readData.append(m_serialPort->readAll());
    //qDebug() << m_readData << m_readData.size();
    if (m_readData.size() == 3) {m_readData = m_readData.left(1);}
    if (m_readData.size() == 4) {m_readData = m_readData.left(2);}
    if (m_readData.size() == 5) {m_readData = m_readData.left(3);}
    if (m_readData.toDouble() != 0){emit ChangeValue(m_readData.toDouble());}
//    {
//        m_readData = m_readData.right(4);
//        m_readData = m_readData.left(2);
//        qDebug() <<  m_readData.toInt();
//        //ui->label->setNum(m_readData.toInt());
//        //qDebug() << m_readData[6] + m_readData[7];
//        //qDebug() << QString(m_readData);

//        //qDebug() << m_readData.remove(1, 5);


//    }


//    if ((QString)m_readData.at(0) == "SPEED")
//    {
//        qDebug() << m_readData;SS
//    }


//    m_readData.append(m_serialPort->readAll());
//    qDebug() << m_readData;
//    if (m_readData.size() < 4) return;

//    if ((uint8_t)m_readData.at(0) == 0xf1)
//    {
//        emit onFrequency(m_readData[0], m_readData[1] ,(uint8_t)m_readData.at(3));
//        qDebug() << ((uint8_t)m_readData.at(3));
//    };
//    if ((uint8_t)m_readData.at(0) == 0xf2)
//    {
//         emit offFrequency(m_readData[0], m_readData[1]);

//    };
//    if ((uint8_t)m_readData.at(0) == 0xf3)

//    {
//        emit controlReport(m_readData[0], m_readData[1]);
//    };

};
