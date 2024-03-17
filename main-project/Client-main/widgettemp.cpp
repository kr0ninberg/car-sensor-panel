#include "widgettemp.h"

WidgetTemp::WidgetTemp(QWidget *parent)
    : QWidget{parent}
{}

void WidgetTemp::slotTemp(QString temp)
{
//    count += 1;
//    qDebug() << "Temp accepted" << temp;
//    if (count == 70){count = -10;}
//    AcceptedTempInt = count;
//    AcceptedTempQString = AcceptedTempQString.number(count);
    AcceptedTempInt = temp.toInt();
    AcceptedTempQString = temp;
    update();
}

void WidgetTemp::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    QPoint center = r.center();

//    qDebug() << this->width() << " " << this->height();
//    painter.drawRect(painter.viewport());

    painter.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap));
    painter.setFont(QFont("Ubuntu", 17, QFont::Medium));
    painter.drawText(QRect(center.x() - 80, 0, 160, 37), Qt::AlignVCenter | Qt::AlignHCenter,  AcceptedTempQString + " °C");
    painter.setFont(QFont("Ubuntu", 12, QFont::Thin));
    painter.drawText(QRect(center.x() - 100, 80-36+3, 200, 36), Qt::AlignVCenter | Qt::AlignHCenter,  "Температура батареи");
    painter.setFont(QFont("Ubuntu", 11, QFont::Medium));
    painter.drawText(QRect(2, 6, 34, 37), Qt::AlignVCenter | Qt::AlignHCenter,  "-10");
    painter.drawText(QRect(this->width()-34-2 , 6, 34, 37), Qt::AlignVCenter | Qt::AlignHCenter,  "70");
    // 36x9
    painter.setPen(Qt::NoPen);
    // if (count  < 0)
    // {
    //     i = 1;
    //     painter.setBrush(QBrush(QColor("#0F59C9"), Qt::SolidPattern));
    //     painter.drawRect(r.left(), center.ry(), 36, 9);
    // }
    painter.setBrush(QBrush(QColor("#0F59C9"), Qt::SolidPattern));
    if (AcceptedTempInt < 0)
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        i = 1;
    }
    else if (AcceptedTempInt < 10)
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        painter.drawRect(r.left()+40, center.ry(), 36, 9);
        i = 2;
    }
    else if (AcceptedTempInt < 20)
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        painter.drawRect(r.left()+40, center.ry(), 36, 9);
        painter.drawRect(r.left()+80, center.ry(), 36, 9);
        i = 3;
    }
    else if (AcceptedTempInt < 30)
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        painter.drawRect(r.left()+40, center.ry(), 36, 9);
        painter.drawRect(r.left()+80, center.ry(), 36, 9);
        painter.drawRect(r.left()+120, center.ry(), 36, 9);
        i = 4;
    }
    else if (AcceptedTempInt < 40)
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        painter.drawRect(r.left()+40, center.ry(), 36, 9);
        painter.drawRect(r.left()+80, center.ry(), 36, 9);
        painter.drawRect(r.left()+120, center.ry(), 36, 9);
        painter.drawRect(r.left()+160, center.ry(), 36, 9);
        i = 5;
    }
    else if (AcceptedTempInt < 50)
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        painter.drawRect(r.left()+40, center.ry(), 36, 9);
        painter.drawRect(r.left()+80, center.ry(), 36, 9);
        painter.drawRect(r.left()+120, center.ry(), 36, 9);
        painter.drawRect(r.left()+160, center.ry(), 36, 9);
        painter.drawRect(r.left()+200, center.ry(), 36, 9);
        i = 6;
    }
    else if (AcceptedTempInt < 60)
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        painter.drawRect(r.left()+40, center.ry(), 36, 9);
        painter.drawRect(r.left()+80, center.ry(), 36, 9);
        painter.drawRect(r.left()+120, center.ry(), 36, 9);
        painter.drawRect(r.left()+160, center.ry(), 36, 9);
        painter.drawRect(r.left()+200, center.ry(), 36, 9);
        painter.drawRect(r.left()+240, center.ry(), 36, 9);
        i = 7;
    }
    else
    {
        painter.drawRect(r.left(), center.ry(), 36, 9);
        painter.drawRect(r.left()+40, center.ry(), 36, 9);
        painter.drawRect(r.left()+80, center.ry(), 36, 9);
        painter.drawRect(r.left()+120, center.ry(), 36, 9);
        painter.drawRect(r.left()+160, center.ry(), 36, 9);
        painter.drawRect(r.left()+200, center.ry(), 36, 9);
        painter.drawRect(r.left()+240, center.ry(), 36, 9);
        painter.drawRect(r.left()+280, center.ry(), 36, 9);
    }
    for (i; i < 8; i++)
    {
        painter.setBrush(QBrush(QColor(22, 48, 87), Qt::SolidPattern));
        painter.drawRect(r.left()+i*40, center.ry(), 36, 9);
    }
}

