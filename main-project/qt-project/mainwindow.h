#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialportreader.h"
#include "serialportmanager.h"
//#include "widgetzx.h"
//#include "widgetst.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    SerialPortReader* reader;
    SerialPortManager *sm;

public slots:
    void ChangeValue(int value);
    void dataRedist(QString, QString);
private:

};

#endif // MAINWINDOW_H
