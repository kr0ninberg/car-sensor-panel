#ifndef WIDGETCHARGE_H
#define WIDGETCHARGE_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QCoreApplication>
#include <QFontDatabase>

class WidgetCharge : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetCharge(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int count = 0;
    int radius = 140;

    int AcceptedChargeInt;
    QString AcceptedChargeQString;

public slots:
    void slotCharge(QString charge);

signals:
};

#endif // WIDGETCHARGE_H
