#pragma once

#include <QMainWindow>
#include "serialportmanager.h"
#include "serialportreader.h"
#include "server.h"
#include <QSerialPort>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<SerialPortReader*> readers;
    SerialPortManager *sm;
    QSqlDatabase db;
    Server* s;

    QTabWidget *tabs;
    void dbinit();
    void mainPanelTab();
    void navigationTab();
    void infoTab();
    void testTab();

    //QMenuBar *menuBar;

    void comReaderInit();						// инициализация работы с датчиками
    bool checkValue(float, float, const QString*, const QString*);
    bool checkValue(int, int, const QString*, const QString*);

public slots:
    void dataRedist(QString, QString);			// обрабатывает данные из датчиков
    void dinamicReaderCreator(QSerialPort*);
    void sendData();							// отправка данных из бд во вне
private:

};
