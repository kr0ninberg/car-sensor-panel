#include "mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <QSizePolicy>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setWindowTitle("Project");
    this->resize(1650, 950);

    tabs = new QTabWidget(this);
    this->setCentralWidget(tabs);
    tabs->setTabsClosable(false);

    //mainPanelTab();
    //navigationTab();
    infoTab();
    //testTab();

    comReaderInit();
}

MainWindow::~MainWindow()
{
}

void MainWindow::mainPanelTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "main panel");

    menuBar = new QMenuBar(w);
    menuBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QVBoxLayout *layoutM = new QVBoxLayout();

    QGridLayout *layout = new QGridLayout();

    //widget = new WidgetAngle(w);		// поворот колес

    //layout->addWidget(widget , 2 , 3 , 1 , 1);

    layoutM->addWidget(menuBar);
    layoutM->addLayout(layout);
    w->setLayout(layoutM);
}

void MainWindow::navigationTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "navigation");

    QGridLayout *layout = new QGridLayout();

    //widget_6 = new WidgetMap(w);		// карта

    //layout->addWidget(widget_6, 1 , 1 , 1 , 1);

    w->setLayout(layout);
}

void MainWindow::infoTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "info");

    QGridLayout *layout = new QGridLayout();

    QLabel *info = new QLabel("some information", w);

    layout->addWidget(info);

    w->setLayout(layout);
}

void MainWindow::testTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "test");


    QGridLayout *layout = new QGridLayout();
    QLabel *info = new QLabel("here may be some widgets to test", w);

    layout->addWidget(info , 1 , 1 , 1 , 1);

    w->setLayout(layout);
}

void MainWindow::comReaderInit(){
    sm = new SerialPortManager(); // init ports when object created
    for(auto port : sm->getSerialPorts()){
        readers.append(new SerialPortReader(port));
        connect(readers.last(), SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
    }
    connect(sm, SIGNAL(newPortReceived(QSerialPort*)), this, SLOT(dinamicReaderCreator(QSerialPort*)));
}

void MainWindow::dataRedist(QString ID, QString value){
//    if(ID == "1") this->ChangeValue(value.toDouble());
//    else if(ID == "0") widget->ValueAngle(value.toDouble());
//    else if(ID == "2") widget_2->ValueZX(value.toDouble());
}

void MainWindow::dinamicReaderCreator(QSerialPort* port){
    readers.append(new SerialPortReader(port));
    connect(readers.last(), SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
}
