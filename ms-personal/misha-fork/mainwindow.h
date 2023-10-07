#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialportreader.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

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
    QSerialPort* serialPort0;
    //void ChangeValue(int value);
public slots:
    void ChangeValue(double value);
private:

};

#endif // MAINWINDOW_H
