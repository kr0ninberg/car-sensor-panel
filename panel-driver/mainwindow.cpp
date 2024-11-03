#include "mainwindow.h"
#include "ui_mainwindow.h"
#define SERVER_IP "127.0.0.1"
//#define SERVER_IP "192.168.0.19"
//#define SERVER_IP "192.168.0.19"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Клиент");
    this->resize(1280, 800);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, QColor(25, 28, 31));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    createActions();
    createMenus();

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::slotDisconnected);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::slotInfo);

    nextBlockSize = 0;

    connect(this, &MainWindow::signalSpeed, ui->widget, &WidgetSpeed::slotSpeed);
    connect(this, &MainWindow::signalRight, ui->widget_2, &WidgetRight::slotRight);
    connect(this, &MainWindow::signalCharge, ui->widget_3, &WidgetCharge::slotCharge);
    connect(this, &MainWindow::signalTemp, ui->widget_4, &WidgetTemp::slotTemp);
    connect(this, &MainWindow::signalTop, ui->widget_5, &WidgetTop::slotTop);

    connect(Variant_1, &QAction::toggled, ui->widget_3, &WidgetCharge::slotVariant1);
    connect(Variant_2, &QAction::toggled, ui->widget_3, &WidgetCharge::slotVariant2);

    connect(Variant_1, &QAction::toggled, ui->widget_2, &WidgetRight::slotVariant1);
    connect(Variant_2, &QAction::toggled, ui->widget_2, &WidgetRight::slotVariant2);

    connect(Variant_1, &QAction::toggled, ui->widget_4, &WidgetTemp::slotVariant1);
    connect(Variant_2, &QAction::toggled, ui->widget_4, &WidgetTemp::slotVariant2);

    connect(ui->widget_3, &WidgetCharge::signalVariant2off, Variant_2, &QAction::setChecked);
    connect(ui->widget_3, &WidgetCharge::signalVariant1off, Variant_1, &QAction::setChecked); // FIXME change connect for readability



    // ui->textBrowser->hide();
    // ui->pushButton->hide();
    // ui->layoutWidget->hide();
}

void MainWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    socket->connectToHost(SERVER_IP , 2323);
}

void MainWindow::createMenus()
{
    Сustomization = menuBar()->addMenu(tr("&Кастомизация")); // FIXME change color

    Сustomization->addAction(Variant_1);
    Сustomization->addAction(Variant_2);
}

void MainWindow::createActions()
{
    Variant_1 = new QAction(tr("&Вариант 1"), this);
    Variant_1->setStatusTip(tr("Первый вариант"));
    Variant_1->setCheckable(true);

    Variant_2 = new QAction(tr("&Вариант 2"), this);
    Variant_2->setStatusTip(tr("Второй вариант"));
    Variant_2->setCheckable(true);
    Variant_2->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// void MainWindow::on_pushButton_clicked()
// {
//     socket->connectToHost(SERVER_IP, 2323); //Attempts to make a connection to hostName on the given port.
// }

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
            //ui->textBrowser->append(ArriveData);
            qDebug() << "ArriveData" << ArriveData;
            ArriveDataList = ArriveData.split(" ");
            qDebug() << "ArriveDataList" << ArriveDataList;
            // for (int i = 0; i < ArriveDataList.size(); i ++)
            // {
            //     qDebug() << "i =" << i << ArriveDataList.at(i);
            //     QLabel *label = findChild<QLabel*>("label_" + QString::number(i));
            //     label->setText(ArriveDataList.at(i));
            // }
            emit signalSpeed(ArriveDataList.at(1));
            emit signalCharge(ArriveDataList.at(2));
            emit signalTop(ArriveDataList.at(3));
            emit signalTemp(ArriveDataList.at(4));
        }
    }
    else
    {
        //ui->textBrowser->append("read error");
    }
}
