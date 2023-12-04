#include "mainwindow.h"
#include "serialportmanager.h"
#include "serialportreader.h"
#include "widgetsc.h"
#include "widgetst.h"
#include "widgetterm.h"
#include "widgetzx.h"
#include <QWidget>
#include <QByteArray>
#include <QDebug>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setWindowTitle("Project");

    //widgets = new QMap<QString, QWidget*>();

    widget_2 = new WidgetZX();
    widget_3 = new WidgetSC();
    widget_4 = new WidgetTerm();

    sm = new SerialPortManager();
    for(auto port : sm->getSerialPorts()){
        readers.append(new SerialPortReader(port));
        connect(readers.last(), SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
    }

}

MainWindow::~MainWindow()
{
}

void MainWindow::ChangeValue(int value)
{
    //label->setNum(value);
    //label_6->setNum(value);
    //label_7->setNum(value);
    //ui->label_13->setNum(value);

}

void MainWindow::dataRedist(QString ID, QString value){
    if(ID == "1") this->ChangeValue(value.toDouble());
    else if(ID == "2") widget_2->ValueZX(value.toDouble());
    else if(ID == "3") widget_3->ValueSC(value.toDouble());
    else if(ID == "4") widget_4->ValueTerm(value.toDouble());
    else if(ID == "all") {
        this->ChangeValue(value.toDouble());
        widget_2->ValueZX(value.toDouble());
        widget_3->ValueSC(value.toDouble());
        widget_4->ValueTerm(value.toDouble());
    }
}
