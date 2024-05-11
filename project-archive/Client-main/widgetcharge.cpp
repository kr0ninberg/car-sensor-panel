#include "widgetcharge.h"
#define FONT "ubuntu"
//#define FONT juraFont

WidgetCharge::WidgetCharge(QWidget *parent)
    : QWidget{parent}
{}

void WidgetCharge::slotCharge(QString charge)
{
//    count += 1;
//    if (count == 100){count = 0;}
//    qDebug() << "Charge accepted" << charge;
    AcceptedChargeInt = charge.toInt();
    AcceptedChargeQString = charge;
//    AcceptedChargeInt = count;
//    AcceptedChargeQString = AcceptedChargeQString.number(count);
    update();
}

void WidgetCharge::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPoint center = painter.viewport().center();
//    painter.drawRect(painter.viewport());

//    QRect r(0,0, this->width(), this->height());
//    QPoint center = r.center();

    painter.setPen(QPen(QColor(15, 89, 201), 15, Qt::SolidLine, Qt::RoundCap));

    painter.drawArc(QRect(10, 10, 260, 260), 1440 , AcceptedChargeInt*57.6);
//    painter.drawText(center, AcceptedChargeQString);
    painter.setFont(QFont(FONT, 40, QFont::Medium));
    painter.setPen(QPen(Qt::white));
    painter.drawText(QRect(center.x() - 110, center.y() - 100, 220, 120), Qt::AlignHCenter | Qt::AlignBottom,  AcceptedChargeQString + " %");
    painter.setFont(QFont(FONT, 14, QFont::Thin));
    painter.setPen(QPen(Qt::white));
    painter.drawText(QRect(center.x() - 110, center.y() + 20, 220, 120), Qt::AlignHCenter | Qt::AlignTop,  "Заряд батареи");

}
