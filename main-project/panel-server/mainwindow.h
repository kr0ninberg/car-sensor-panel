#pragma once

#include <QMainWindow>
#include "serialportmanager.h"
#include "serialportreader.h"

#include <QSerialPort>
#include <QDebug>
#include <QPainter>
#include <QAction>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<SerialPortReader*> readers;
    SerialPortManager *sm;

    QTabWidget *tabs;
    void mainPanelTab();
    void navigationTab();
    void infoTab();
    void testTab();

    QMenuBar *menuBar;

    void comReaderInit();

public slots:
    void dataRedist(QString, QString);
    void dinamicReaderCreator(QSerialPort*);

private:

};
