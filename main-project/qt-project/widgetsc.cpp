#include "widgetsc.h"

WidgetSC::WidgetSC(QWidget *parent)
    : QWidget{parent}
{

}

void WidgetSC::ValueSC(int value)
{
    num_lb13 = value;
    update();
}

void WidgetSC::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    qDebug() << this->width();
    qDebug() << this->height();
    //421 421

    QRect r(0,0, this->width(), this->height());
    QPoint cent = r.center();

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

    painter.drawRect(r);
    painter.drawEllipse(cent, radiusx, radiusx);

    painter.translate(cent);

    QPoint p1(radiusx-20,0);
    QPoint p2(radiusx, 0);
    int i = 10;
    for (int count = 1; count <=36; count++)
    {
        if (count <= 4 || count > 15)
        {
            if (count % 4 == 0)
            {
                painter.setPen(QPen(Qt::black, 7, Qt::SolidLine, Qt::FlatCap));
                painter.drawLine(p1, p2);
                painter.rotate(i);
            }
            else
            {
                painter.setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap));
                painter.drawLine(p1, p2);
                painter.rotate(i);
            }
        }
        else
        {
            painter.rotate(i);
        }
    }

    painter.resetTransform();
    painter.translate(cent);
    painter.rotate(-210);
    painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));

    if (num_lb13 != 0)
    {
        painter.rotate(num_lb13*2.4);
        QPoint p3(0,0);
        QPoint p4(radiusx, 0);
        painter.drawLine(p3,p4);
    }
}
