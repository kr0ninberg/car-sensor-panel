#ifndef WIDGETSPEED_H
#define WIDGETSPEED_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QFontDatabase>
#include <QCoreApplication>

class WidgetSpeed : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetSpeed(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int count = 0;
    int radius = 525/2;
    int AcceptedSpeedInt;
    QString AcceptedSpeedQString;

public slots:
    void slotSpeed(QString speed);

signals:
};

#endif // WIDGETSPEED_H
