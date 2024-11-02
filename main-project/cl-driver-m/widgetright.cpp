#include "widgetright.h"

WidgetRight::WidgetRight(QWidget *parent)
    : QWidget{parent}
{
    checkedVariant1 = false;
    checkedVariant2 = true;
}

void WidgetRight::slotRight()
{
    update();
}

void WidgetRight::slotVariant1(bool checked)
{
    qDebug() << "slotVariant1" << "checked" << checked;
    checkedVariant1 = checked;
    update();
}

void WidgetRight::slotVariant2(bool checked)
{
    qDebug() << "slotVariant2" << "checked" << checked;
    checkedVariant2 = checked;
    update();
}

void WidgetRight::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
////////////////////////////

    QPixmap Distance(":/Distance_icon.png");
    QPixmap AVG(":/AVG_icon.png");
    QPixmap Power(":/Power_icon.png");

    QPoint center = painter.viewport().center();

    if(checkedVariant1)
    {
        this->move(QPoint(960, 312));
        this->setFixedSize(265,257);

        painter.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap));
        painter.setFont(QFont("Ubuntu", 17, QFont::Medium));
        painter.drawText(QRect(74, 4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "172 км");
        painter.drawText(QRect(74, 86+3+4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "43 втч/км");
        painter.drawText(QRect(74, 86*2+8+4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "84 км");
        painter.setFont(QFont("Ubuntu", 12, QFont::Thin));
        painter.drawText(QRect(74, 46-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Пробег за день");
        painter.drawText(QRect(74, 46+86+3-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Ср. расход энергии");
        painter.drawText(QRect(74, 46+86*2+8-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Запас хода");

        painter.drawPixmap(QPoint(painter.viewport().x(), center.y() - 100), Distance);
        painter.drawPixmap(QPoint(painter.viewport().x(), center.y() - 10), AVG);
        painter.drawPixmap(QPoint(painter.viewport().x(), center.ry() +80), Power);
    }
    if (checkedVariant2)
    {
        this->move(QPoint(243, 650));
        this->setFixedSize(794,80);
        painter.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap));

        //painter.drawRect(painter.viewport());
        ////
        painter.setFont(QFont("Ubuntu", 17, QFont::Medium));
        painter.drawText(QRect(70, 4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "172 км");
        painter.drawText(QRect(370, 4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "43 втч/км");
        painter.drawText(QRect(690, 4, 200, 46), Qt::AlignVCenter | Qt::AlignLeft,  "84 км");
        /////
        painter.setFont(QFont("Ubuntu", 12, QFont::Thin));
        painter.drawText(QRect(70, 46-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Пробег за день");
        painter.drawText(QRect(370, 46-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Ср. расход энергии");
        painter.drawText(QRect(690, 46-4, 200, 40), Qt::AlignVCenter | Qt::AlignLeft,  "Запас хода");
        ////
        painter.drawPixmap(QPoint(0, 25), Distance);
        painter.drawPixmap(QPoint(300, 25), AVG);
        painter.drawPixmap(QPoint(620, 25), Power);
    }
////////////////////////
    // painter.setPen(QPen(QColor(15, 89, 201), 12, Qt::SolidLine, Qt::RoundCap));

    // painter.drawArc(QRect(10, 10, 260, 260), 1440 , count*57.6);
    // painter.drawText(center, AcceptedChargeQString);
}
