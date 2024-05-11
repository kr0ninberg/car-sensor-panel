#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QQuickView *view = new QQuickView();

    // QWidget *container = QWidget::createWindowContainer(view, this);

    // view->setSource(QUrl("Mapping.qml"));

    // ui->verticalLayout->addWidget(container);

    // ui->quickWidget = new QQuickWidget;
    // QQuickWidget *view = new QQuickWidget;

    connect(ui->quickWidget, &QQuickWidget::statusChanged, this, &MainWindow::statusChanged);
    ui->quickWidget->setSource(QUrl::fromLocalFile("Mapping.qml"));
    ui->quickWidget->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::statusChanged(QQuickWidget::Status status)
{
    qDebug() << "status" << status;
}
