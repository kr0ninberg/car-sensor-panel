#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "serialportreader.h"
#include <QByteArray>
#include <QDebug>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Project");
    serialPort0 = new QSerialPort(this);
    serialPort0->open(QIODevice::ReadWrite);
    serialPort0->setPortName("/dev/ttyACM0");
    serialPort0->setBaudRate(QSerialPort::Baud115200);
    serialPort0->setDataBits(QSerialPort::Data8);
    serialPort0->setStopBits(QSerialPort::OneStop);
    serialPort0->setParity(QSerialPort::NoParity);
    serialPort0->setFlowControl(QSerialPort::NoFlowControl);
    serialPort0->open(QIODevice::ReadOnly);

    if (serialPort0->isOpen())
    {
        qDebug() << "Is Open";
    }
    else{
        qDebug() << "Is Not Open";
    }

    reader = new SerialPortReader(serialPort0);
    reader->handleReadyRead();
    //serialPort0->close();

    connect(reader, &SerialPortReader::ChangeValue, this, &MainWindow::ChangeValue);
    ui->label_3->setText("°C");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeValue(double value)
{
    ui->label->setNum(value);
}
