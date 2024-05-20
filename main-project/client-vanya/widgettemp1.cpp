#include "widgettemp1.h"

WidgetTemp1::WidgetTemp1(QWidget *parent)
    : QWidget{parent}
{
    checkedVariant1 = false;
    checkedVariant2 = true;
}

void WidgetTemp1::slotTemp(QString temp)
{
    count += 1;
    count_2 +=1;
    qDebug() << "Temp accepted" << temp;
    if (count == 70){count = -10;}
    if (count_2 == 80){count_2 = 0;}
    AcceptedTempInt = count;
    AcceptedTempQString = AcceptedTempQString.number(count);
    // AcceptedTempInt = temp.toInt();
    // AcceptedTempQString = temp;
    update();
}

void WidgetTemp1::slotVariant1(bool checked)
{
    qDebug() << "slotVariant1" << "checked" << checked;
    checkedVariant1 = checked;
    update();
}

void WidgetTemp1::slotVariant2(bool checked)
{
    qDebug() << "slotVariant2" << "checked" << checked;
    checkedVariant2 = checked;
    update();
}

void WidgetTemp1::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    QPoint center = r.center();
    ////////////////////////////////

    //    if (checkedVariant2)
    //    {
    //        this->move(QPoint(1000, 136));
    //        this->setFixedSize(280,527);

    //        painter.setPen(QPen(Qt::lightGray, 2, Qt::SolidLine));
    //        painter.drawArc(QRect(30-1025, -229-136, 1250, 1250), -390, 770);

    //        painter.setPen(QPen(QColor(15, 89, 201), 15, Qt::SolidLine, Qt::RoundCap));
    //        painter.drawArc(QRect(30-1025, -229-136, 1250, 1250), -390, 9.625*count_2);

    //        painter.setBrush(QBrush(Qt::lightGray));
    //        painter.setPen(Qt::NoPen);
    //        painter.drawRoundedRect(184, 517, 30, 10, 5, 5);
    //        painter.drawRoundedRect(185, 0, 30, 10, 5, 5);

    //        //    painter.drawText(center, AcceptedChargeQString);
    //        painter.setFont(QFont("Ubuntu", 40, QFont::Medium));
    //        painter.setPen(QPen(Qt::white));
    //        painter.drawText(QRect(center.x() - 110, center.y() - 100, 220, 120), Qt::AlignHCenter | Qt::AlignBottom,  AcceptedTempQString + " °C");
    //        painter.setFont(QFont("Ubuntu", 14, QFont::Thin));
    //        painter.setPen(QPen(Qt::white));
    //        painter.drawText(QRect(center.x() - 110, center.y() + 20, 220, 120), Qt::AlignHCenter | Qt::AlignTop,  "Температура батареи");
    //    }
        //this->move(QPoint(480, 650));
        this->setFixedSize(320, 98);

        //        painter.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap));
        //        painter.setFont(QFont("Ubuntu", 17, QFont::Medium));
        //        painter.drawText(QRect(center.x() - 80, 0, 160, 37), Qt::AlignVCenter | Qt::AlignHCenter,  AcceptedTempQString + " °C");
        //        painter.setFont(QFont("Ubuntu", 12, QFont::Thin));
        //        painter.drawText(QRect(center.x() - 100, 55, 200, 36), Qt::AlignVCenter | Qt::AlignHCenter,  "Температура батареи");
        //        painter.setFont(QFont("Ubuntu", 11, QFont::Medium));
        //        painter.drawText(QRect(2, 6, 34, 37), Qt::AlignVCenter | Qt::AlignHCenter,  "-10");
        //        painter.drawText(QRect(this->width()-34-2 , 6, 34, 37), Qt::AlignVCenter | Qt::AlignHCenter,  "70");

        //        painter.setPen(Qt::NoPen);
        painter.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap));
        painter.setFont(QFont("Ubuntu", 17, QFont::Medium));
        painter.drawText(QRect(center.x() - 80, 0, 160, 37), Qt::AlignVCenter | Qt::AlignHCenter,  AcceptedTempQString + " °C");
            painter.setFont(QFont("Ubuntu", 12, QFont::Thin));
        painter.drawText(QRect(center.x() - 140, 55, 260, 36), Qt::AlignVCenter | Qt::AlignHCenter,  "Температура электродвигателя");
        painter.setFont(QFont("Ubuntu", 11, QFont::Medium));
        painter.drawText(QRect(2, 6, 34, 37), Qt::AlignVCenter | Qt::AlignHCenter,  "-10");
        painter.drawText(QRect(this->width()-34-2 , 6, 34, 37), Qt::AlignVCenter | Qt::AlignHCenter,  "70");
        painter.setPen(Qt::NoPen);
        int temp_range = AcceptedTempInt / 10;
        int color_range = temp_range / 5; // Divide the temperature range into 5 equal parts

        QColor color(0, 0, 0, 0);

        if (AcceptedTempInt < 0)
        {
            i = 1;
            color = Qt::green;
        }
        else if (AcceptedTempInt < 10)
        {
            color = Qt::green;
            i = 2;
        }
        else if (AcceptedTempInt < 20)
        {
            color = Qt::green;
            i = 3;
        }
        else if (AcceptedTempInt < 30)
        {
            color = Qt::yellow;
            i = 4;
        }
        else if (AcceptedTempInt < 40)
        {
            color = Qt::yellow;
            i = 5;
        }
        else if (AcceptedTempInt < 50)
        {
            color = Qt::yellow;
            i = 6;
        }
        else if (AcceptedTempInt < 60)
        {
            color = Qt::red;
            i = 7;
        }
        else
        {
            color = Qt::red;
            i = 8;
        }

        // Draw the rectangles with the appropriate color
        painter.setBrush(QBrush(color));
        for (int j = 0; j < i; j++)
        {
            painter.drawRect(r.left()+j*40, center.ry(), 36, 9);
        }
}



