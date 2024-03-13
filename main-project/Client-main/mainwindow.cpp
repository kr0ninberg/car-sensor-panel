#include "mainwindow.h"
#include "ui_mainwindow.h"
#define IP "127.0.0.1"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::slotDisconnected);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::slotInfo);
    nextBlockSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost(IP, 2323); //Attempts to make a connection to hostName on the given port.
}

void MainWindow::slotInfo()
{
    qDebug() << "INFORMATION ABOUT CLIENT CONNECTION SOCKET";
    qDebug() << "socketDescriptor()" << socket->socketDescriptor();
    qDebug() << "isValid()" << socket->isValid();
    qDebug() << "PeerPort()" << socket->peerPort() << "PeerAddress()" << socket->peerAddress() << "PeerName()" << socket->peerName();
    qDebug() << "localPort()" << socket->localPort() << "localAddress()" << socket->localAddress();
}

void MainWindow::slotDisconnected()
{
    qDebug() << "slotDisconnected Client";
    socket = (QTcpSocket*)sender();
    socket->deleteLater();
}

void MainWindow::slotReadyRead()
{
    qDebug() << "Data arrive";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_15);
    if(in.status() == QDataStream::Ok)
    {
        for(;;)
        {
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize client" << nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            QTime time;
            in >> time >> str;
            nextBlockSize = 0;
            qDebug() << "Data client" << str;
            ArriveData = time.toString() + " " + str;
            ui->textBrowser->append(ArriveData);
            qDebug() << "ArriveData" << ArriveData;
            ArriveDataList = ArriveData.split(" ");
            qDebug() << "ArriveDataList" << ArriveDataList;
            for (int i = 0; i < ArriveDataList.size(); i ++)
            {
                qDebug() << "i =" << i << ArriveDataList.at(i);
                QLabel *label = findChild<QLabel*>("label_" + QString::number(i));
                label->setText(ArriveDataList.at(i));
            }
        }
    }
    else
    {
        ui->textBrowser->append("read error");
    }
}
