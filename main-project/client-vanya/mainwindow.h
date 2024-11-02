#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>
#include <QHostAddress>
#include <QStyle>
#include <QPalette>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void showEvent(QShowEvent* event) override;

    void createMenus();
    void createActions();
    void baseValueInit();

    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
    QByteArray Data;
    quint16 nextBlockSize;
    QString ArriveData;
    QStringList ArriveDataList;

    QMenu *Сustomization;
    QAction* Variant_1;
    QAction* Variant_2;


public slots:
    void slotReadyRead();
    void slotInfo();
    void slotDisconnected();

signals:
    void signalSpeed(QString speed);
    void signalCharge(QString charge);
    void signalTemp(QString temp);
    void signalRight();
    void signalTop(QString temp);
};
#endif // MAINWINDOW_H
