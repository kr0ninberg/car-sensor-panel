#ifndef WIDGETTERM_H
#define WIDGETTERM_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetTerm: public QWidget
{
    Q_OBJECT
public:
    WidgetTerm(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int num_lb;
    int i = 10;
    int radiusx = 140;

public slots:
    void ValueTerm(int value);

};

#endif // WIDGETTERM_H
