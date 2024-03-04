#pragma once

#include <QMainWindow>
#include "serialportmanager.h"
#include "serialportreader.h"
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
    QSqlTableModel *model;
    QSqlTableModel *model_2;
    QSqlTableModel *model_3;
    QTableView *table_view;
    QTableView *table_view_2;
    QTableView *table_view_3;

    QTabWidget *tabs;
    void mainPanelTab();
    void navigationTab();
    void infoTab();
    void testTab();

    //QMenuBar *menuBar;

    void comReaderInit();

public slots:
    void dataRedist(QString, QString);
    void dinamicReaderCreator(QSerialPort*);

private:

};
