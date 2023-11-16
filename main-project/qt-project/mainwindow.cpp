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

    sm = new SerialPortManager("/dev/ttyACM0");
    reader = new SerialPortReader(sm->getSerialPort());
    //reader->handleReadyRead();


    //2 указателя - 2 объекта

    //connect(reader, &SerialPortReader::ChangeValue, this, &MainWindow::ChangeValue);
    //connect(reader, &SerialPortReader::ChangeValue, ui->widget_2, &WidgetZX::ValueZX);
    //connect(reader, &SerialPortReader::ChangeValue, ui->widget_3, &WidgetSC::ValueSC);
    //connect(reader, &SerialPortReader::ChangeValue, ui->widget_4, &WidgetTerm::ValueTerm);

    connect(reader, SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeValue(int value)
{
    ui->label->setNum(value);
    ui->label_6->setNum(value);
    ui->label_7->setNum(value);
    //ui->label_13->setNum(value);

}

void MainWindow::dataRedist(QString ID, QString value){
    if(ID == "1") this->ChangeValue(value.toDouble());
    else if(ID == "2") ui->widget_2->ValueZX(value.toDouble());
    else if(ID == "3") ui->widget_3->ValueSC(value.toDouble());
    else if(ID == "4") ui->widget_4->ValueTerm(value.toDouble());
    else if(ID == "all") {
        this->ChangeValue(value.toDouble());
        ui->widget_2->ValueZX(value.toDouble());
        ui->widget_3->ValueSC(value.toDouble());
        ui->widget_4->ValueTerm(value.toDouble());
    }
}
