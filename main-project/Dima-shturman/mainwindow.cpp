#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_radiowindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Инициализируем второе окно
    sWindow = new RadioWindow();
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(sWindow, &RadioWindow::firstWindow, this, &MainWindow::show);



}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);


    QPixmap Back(":/resources/Background.png"); //./Background.png
    QPixmap Wifi(":/resources/Wifi.png");
    QPixmap Autoicon(":/resources/Auto icon.png");
    QPixmap Radioicon(":/resources/Radio icon.png");

    QPixmap Charge(":/resources/Charge.png");
    QPixmap Car(":/resources/Main car.png");
    QPixmap Pause(":/resources/Music pause.png");
    QPixmap ArLeft(":/resources/Arrows left.png");
    QPixmap ArRight(":/resources/Arrows right.png");

    //Задний фон
    painter.drawPixmap (QPoint(0, 20), Back);


    //Верхняя панель
    painter.setPen("gray");

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(Qt::gray);
    painter.drawRect(0, 0, 1440, 40);               //Добавить время и проценты заряда
    painter.drawPixmap (QPoint(1400, 9), Wifi);


    //Нижняя панель
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(Qt::black);
    painter.drawRect(0, 820, 1440, 80);
    painter.drawPixmap (QPoint(25, 845), Autoicon);
    painter.drawPixmap (QPoint(1330, 840), Radioicon);

    painter.drawPixmap (QPoint(510, 5), Charge);

    painter.drawPixmap(0, 0, 500, 820, Car);

    //MusicPad
    painter.setPen("darkGray");

    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(Qt::darkGray);

    QRectF MusicPad(620, 125, 700, 140);
    painter.drawRoundedRect(MusicPad, 20.0, 15.0);
    painter.drawPixmap (QPoint(1085, 175), ArLeft);
    painter.drawPixmap (QPoint(1171, 179), Pause); //86
    painter.drawPixmap (QPoint(1237, 175), ArRight); //152

    //Music icon
    painter.setPen("gray");
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(Qt::gray);

    QRectF MusicIcon(707, 160, 70, 70);
    painter.drawRoundedRect(MusicIcon, 20.0, 15.0);
}


void MainWindow::on_radioButton_clicked()
{
    sWindow->show();  // Показываем второе окно
    this->close();    // Закрываем основное окно
}
