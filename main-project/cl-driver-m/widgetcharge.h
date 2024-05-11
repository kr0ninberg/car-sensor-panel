#ifndef WIDGETCHARGE_H
#define WIDGETCHARGE_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetCharge : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetCharge(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int count = 0;
    int radius = 140;

    bool checkedVariant1;
    bool checkedVariant2;

    int AcceptedChargeInt;
    QString AcceptedChargeQString;

public slots:
    void slotCharge(QString charge);
    void slotVariant1(bool checked);
    void slotVariant2(bool checked);

signals:
    void signalVariant2off(bool);
    void signalVariant1off(bool);
};

#endif // WIDGETCHARGE_H
