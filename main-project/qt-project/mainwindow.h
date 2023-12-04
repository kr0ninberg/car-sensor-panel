#pragma once

#include "mainwindow.h"
#include "serialportmanager.h"
#include "serialportreader.h"
#include "widgetsc.h"
#include "widgetst.h"
#include "widgetterm.h"
#include "widgetzx.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QPainter>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<SerialPortReader*> readers;
    SerialPortManager *sm;

    //QMap<QString, QWidget*> *widgets;
    WidgetZX *widget_2;
    WidgetSC *widget_3;
    WidgetTerm *widget_4;

public slots:
    void ChangeValue(int value);
    void dataRedist(QString, QString);
private:

};
