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
    s = new Server();
    connect(s, SIGNAL(mishaNeedSomeData()), this, SLOT(sendData()));
    dbinit();

    mainPanelTab();
    //navigationTab();
    //infoTab();
    //testTab();
    comReaderInit();
}

MainWindow::~MainWindow()
{
    db.close();
}

void MainWindow::dbinit(){
    db = QSqlDatabase::addDatabase(DBTYPE);
    db.setDatabaseName(DBNAME);
    if(!db.open()){
        qCritical() << "При подключении произошла ошибка: " << db.lastError().databaseText();
        return;
    }
    qDebug() << "База данных подключена" << db.databaseName();
}

void MainWindow::mainPanelTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "main panel");

    /*menuBar = new QMenuBar(w);
    menuBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QVBoxLayout *layoutM = new QVBoxLayout();*/
    QGridLayout *layout = new QGridLayout();

    QSqlTableModel *model;
    QSqlTableModel *model_2;
    QSqlTableModel *model_3;
    QTableView *table_view;
    QTableView *table_view_2;
    QTableView *table_view_3;

    table_view = new QTableView(w);
    table_view_2 = new QTableView(w);
    table_view_3 = new QTableView(w);


    model = new QSqlTableModel(this, db);
    model->setTable("test_sensor_1");
    model->select();



    table_view->setModel(model);
    model_2 = new QSqlTableModel(this, db);
    model_2->setTable("test_sensor_4");
    //QSqlQuery query1("SELECT Value FROM test_sensor_4 ORDER BY id DESC LIMIT 1");
    model_2->select();
    table_view_2->setModel(model_2);

//    QTimer *timer = new QTimer(this);		// это должен был быть опрос датчиков по таймеру [может как-нибудь потом]
//    timer->setInterval(5000);
//    connect(timer, SIGNAL(timeout()), model_2, SLOT(select()));
//    timer->start();

    layout->addWidget(table_view , 1 , 1);
    layout->addWidget(table_view_2 , 1 , 2);
    layout->addWidget(table_view_3 , 1 , 3);
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
    if(ID == "accel"){
        if(!checkValue(0, 120, &ID, &value)) return;
        QSqlQuery query;
        query.prepare("INSERT INTO test_sensor_1 (value, timestamp) VALUES (:value1, CURRENT_TIMESTAMP)");
        query.bindValue(":value1", value);

        if (query.exec()) {
            qDebug() << "Запись успешно добавлена";
        } else {
            qCritical() << "Ошибка при добавлении записи:" << query.lastError().text();
        }
    }else if(ID == "tbat"){
        if(!checkValue(-10.0f, 70.0f, &ID, &value)) return;
        value = QString::number(int(value.toFloat()));
        QSqlQuery query;
        query.prepare("INSERT INTO test_sensor_2 (value, timestamp) VALUES (:value1, CURRENT_TIMESTAMP)");
        query.bindValue(":value1", value);

        if (query.exec()) {
            qDebug() << "Запись успешно добавлена";
        } else {
            qCritical() << "Ошибка при добавлении записи:" << query.lastError().text();
        }
    }else if(ID == "tout"){
        if(!checkValue(-30.0f, 40.0f, &ID, &value)) return;
        value = QString::number(int(value.toFloat()));
        QSqlQuery query;
        query.prepare("INSERT INTO test_sensor_3 (value, timestamp) VALUES (:value1, CURRENT_TIMESTAMP)");
        query.bindValue(":value1", value);

        if (query.exec()) {
            qDebug() << "Запись успешно добавлена";
        } else {
            qCritical() << "Ошибка при добавлении записи:" << query.lastError().text();
        }
    }else if(ID == "bat"){
        if(!checkValue(0, 100, &ID, &value)) return;
        QSqlQuery query;
        query.prepare("INSERT INTO test_sensor_4 (value, timestamp) VALUES (:value1, CURRENT_TIMESTAMP)");
        query.bindValue(":value1", value);

        if (query.exec()) {
            qDebug() << "Запись успешно добавлена";
        } else {
            qCritical() << "Ошибка при добавлении записи:" << query.lastError().text();
        }
    }
}

void MainWindow::dinamicReaderCreator(QSerialPort* port){
    readers.append(new SerialPortReader(port));
    connect(readers.last(), SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
}

void MainWindow::sendData(){
    QString res = "";
    QSqlQuery query1("SELECT Value FROM test_sensor_1 ORDER BY id DESC LIMIT 1");
    while (query1.next()){
        res += query1.value("Value").toString();
    }
    res += " ";
    QSqlQuery query4("SELECT Value FROM test_sensor_4 ORDER BY id DESC LIMIT 1");
    while (query4.next()){
        res += query4.value("Value").toString();
    }
    res += " ";
    QSqlQuery query3("SELECT Value FROM test_sensor_3 ORDER BY id DESC LIMIT 1");
    while (query3.next()){
        res += query3.value("Value").toString();
    }
    res += " ";
    QSqlQuery query2("SELECT Value FROM test_sensor_2 ORDER BY id DESC LIMIT 1");
    while (query2.next()){
        res += query2.value("Value").toString();
    }

    qDebug() << res;
    s->SendToClient(res);
}

bool MainWindow::checkValue(float left, float right, const QString* id, const QString* value){
    bool *ok = new bool();
    float val = value->toFloat(ok);
    if(!*ok){
        qWarning() << QString("conversion failure [id = %1, value = %2]").arg(*id).arg(*value);
        return false;
    }
    if(val < left || val > right){
        qWarning() << QString("value out of range [id = %1, value = %2]").arg(*id).arg(*value);
        return false;
    }
    return true;
}

bool MainWindow::checkValue(int left, int right, const QString* id, const QString* value){
    bool *ok = new bool();
    int val = value->toInt(ok);
    if(!*ok){
        qWarning() << QString("conversion failure [id = %1, value = %2]").arg(*id).arg(*value);
        return false;
    }
    if(val < left || val > right){
        qWarning() << QString("value out of range [id = %1, value = %2]").arg(*id).arg(*value);
        return false;
    }
    return true;
}
