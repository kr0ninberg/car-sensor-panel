#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>
#include <QHostAddress>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
    QByteArray Data;
    quint16 nextBlockSize;
    QString ArriveData;
    QStringList ArriveDataList;

public slots:
    void slotReadyRead();
    void slotInfo();
    void slotDisconnected();

};
#endif // MAINWINDOW_H
