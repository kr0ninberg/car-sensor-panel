#pragma once

#include <QMainWindow>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTabWidget *tabs;
    void mainPanelTab();
    void navigationTab();
    void infoTab();
    void testTab();

    //QMenuBar *menuBar;


public slots:

private:

};
