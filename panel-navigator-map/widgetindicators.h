#ifndef WIDGETINDICATORS_H
#define WIDGETINDICATORS_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetIndicators : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetIndicators(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:
};

#endif // WIDGETINDICATORS_H
