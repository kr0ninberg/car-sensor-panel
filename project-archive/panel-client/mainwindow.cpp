#include "mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <QSizePolicy>

//#define DBTYPE "QSQLITE"
#define DBTYPE "QPSQL"
#define DBNAME "testdb"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setWindowTitle("Project");
    this->resize(1650, 950);

    tabs = new QTabWidget(this);
    this->setCentralWidget(tabs);
    tabs->setTabsClosable(false);

    mainPanelTab();
    //navigationTab();
    infoTab();
    //testTab();

}

MainWindow::~MainWindow()
{
}

void MainWindow::mainPanelTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "main panel");

    /*menuBar = new QMenuBar(w);
    menuBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QVBoxLayout *layoutM = new QVBoxLayout();*/
    QGridLayout *layout = new QGridLayout();

    //widget = new WidgetAngle(w);		// поворот колес
    //layout->addWidget(widget , 2 , 3 , 1 , 1);
    /*layoutM->addWidget(menuBar);
    layoutM->addLayout(layout);*/

//    layout->addWidget(table_view , 1 , 1);
//    layout->addWidget(table_view_2 , 1 , 2);
//    layout->addWidget(table_view_3 , 1 , 3);

    w->setLayout(layout); // layoutM
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
