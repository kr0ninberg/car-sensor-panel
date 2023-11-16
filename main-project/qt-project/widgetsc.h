#ifndef WIDGETSC_H
#define WIDGETSC_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetSC : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetSC(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int num_lb13;
    int i = 10;
    int radiusx = 200;
public slots:
    void ValueSC(int value);
};

#endif // WIDGETSC_H
