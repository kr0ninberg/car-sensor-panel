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

    comReaderInit();
}

MainWindow::~MainWindow()
{
    db.close();
}

void MainWindow::mainPanelTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "main panel");

    /*menuBar = new QMenuBar(w);
    menuBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QVBoxLayout *layoutM = new QVBoxLayout();*/
    QGridLayout *layout = new QGridLayout();

    table_view = new QTableView(w);
    table_view_2 = new QTableView(w);
    table_view_3 = new QTableView(w);
    db = QSqlDatabase::addDatabase(DBTYPE);
    db.setDatabaseName(DBNAME);
    if(!db.open()){
        qDebug() << "При подключении произошла ошибка: " << db.lastError().databaseText();
        return;
    }
    qDebug() << "База данных подключена" << db.databaseName();

    model = new QSqlTableModel(this, db);
    model ->setTable("test_sensor_1");
    model->select();
    table_view->setModel(model);
    model_2 = new QSqlTableModel(this, db);
    model_2 ->setTable("test_sensor_2");
    model_2->select();
    table_view_2->setModel(model_2);

    /*QSqlQuery query1("SELECT Fruit, Price FROM Products ORDER BY Price DESC LIMIT 1");
    while (query1.next()){
        QString Fruit = query1.value("Fruit").toString();
        int Price = query1.value("Price").toInt();
        qDebug() << Fruit << Price;
    }*/
    //widget = new WidgetAngle(w);		// поворот колес
    //layout->addWidget(widget , 2 , 3 , 1 , 1);
    /*layoutM->addWidget(menuBar);
    layoutM->addLayout(layout);*/

    layout->addWidget(table_view , 1 , 1);
    layout->addWidget(table_view_2 , 1 , 2);
    layout->addWidget(table_view_3 , 1 , 3);
    QPushButton button("reload", w);
    connect(&button, SIGNAL(clicked(bool)), table_view_2, SLOT(update()));
    layout->addWidget(&button , 1 , 4);
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
    if(ID == "2"){
        QSqlQuery query;
        query.prepare("INSERT INTO test_sensor_2 (value, timestamp) VALUES (:value1, CURRENT_TIMESTAMP)");
        query.bindValue(":value1", value);

        if (query.exec()) {
            qDebug() << "Запись успешно добавлена";
        } else {
            qDebug() << "Ошибка при добавлении записи:" << query.lastError().text();
        }
    }
}

void MainWindow::dinamicReaderCreator(QSerialPort* port){
    readers.append(new SerialPortReader(port));
    connect(readers.last(), SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
}
