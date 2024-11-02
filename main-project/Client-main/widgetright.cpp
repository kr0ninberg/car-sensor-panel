#include "widgetright.h"
#define FONT "ubuntu"
//#define FONT juraFont

WidgetRight::WidgetRight(QWidget *parent)
    : QWidget{parent}
{}

void WidgetRight::slotRight()
{
    update();
}

void WidgetRight::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPoint center = painter.viewport().center();
//    painter.drawRect(painter.viewport());

    qDebug() << this->width() << " " << this->height();
    QPixmap Distance(":/Distance_icon.png");
    QPixmap AVG(":/AVG_icon.png");
    QPixmap Power(":/Power_icon.png");
    //QImage Speed("Speed.bmp");

    painter.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap));
    painter.setFont(QFont(FONT, 17, QFont::Medium));
    painter.drawText(QRect(74, 4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "172 км");
    painter.drawText(QRect(74, 86+3+4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "43 втч/км");
    painter.drawText(QRect(74, 86*2+8+4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "84 км");
    painter.setFont(QFont(FONT, 12, QFont::Thin));
    painter.drawText(QRect(74, 46-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Пробег за день");
    painter.drawText(QRect(74, 46+86+3-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Ср. расход энергии");
    painter.drawText(QRect(74, 46+86*2+8-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Запас хода");

    painter.drawPixmap(QPoint(painter.viewport().x(), center.y() - 100), Distance);
    painter.drawPixmap(QPoint(painter.viewport().x(), center.y() - 10), AVG);
    painter.drawPixmap(QPoint(painter.viewport().x(), center.ry() +80), Power);

    // painter.setPen(QPen(QColor(15, 89, 201), 12, Qt::SolidLine, Qt::RoundCap));

    // painter.drawArc(QRect(10, 10, 260, 260), 1440 , count*57.6);
    // painter.drawText(center, AcceptedChargeQString);
}
