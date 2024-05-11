#include "widgetindicators.h"

WidgetIndicators::WidgetIndicators(QWidget *parent)
    : QWidget{parent}
{

}

void WidgetIndicators::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // QPixmap Wether("Wether.png");
    // QPixmap Wether_2("Wether_2.png");
    // QPixmap Moon("Moon.png");
    // QPixmap Сonnection("Сonnection.png");

    QPixmap Indicators("Indicators.png");

    //painter.drawRect(painter.viewport());

    painter.drawPixmap(QPoint(25, 150), Indicators);
    // painter.drawPixmap(QPoint(0, 0), Wether);
    // painter.drawPixmap(QPoint(317, 12), Wether_2);
    // painter.drawPixmap(QPoint(494, 12), Moon);
    // painter.drawPixmap(QPoint(929, 12), Сonnection);
}
