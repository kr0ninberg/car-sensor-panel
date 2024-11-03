#include "widgetcharge.h"

WidgetCharge::WidgetCharge(QWidget *parent)
    : QWidget{parent}
{
    checkedVariant1 = false;
    checkedVariant2 = true;
}

void WidgetCharge::slotCharge(QString charge)
{
   count += 1;
   if (count == 100){count = 0;}
   qDebug() << "Charge accepted" << charge;
//     AcceptedChargeInt = charge.toInt();
//     AcceptedChargeQString = charge;
   AcceptedChargeInt = count;
   AcceptedChargeQString = AcceptedChargeQString.number(count);
   update();
}

void WidgetCharge::slotVariant1(bool checked)
{
    qDebug() << "WidgetCharge::slotVariant1" << "checked" << checked;
    checkedVariant1 = checked;
    if (checked){emit signalVariant2off(false);}
    update();
}

void WidgetCharge::slotVariant2(bool checked)
{
    qDebug() << "WidgetCharge::slotVariant2" << "checked" << checked;
    checkedVariant2 = checked;
    if (checked){emit signalVariant1off(false);}
    update();
}

void WidgetCharge::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPoint center = painter.viewport().center();
//    if (checkedVariant2)
//    {
//        this->move(QPoint(0, 136));
//        this->setFixedSize(280, 527);

//        int border = 7;
//        int rectTop = height() / 3.5 - 2 * border; // Position the rectangle in the middle of the widget

//        // Draw the rectangle
//        QRectF rect(border, rectTop, width() - 2 * border, height() / 9 - 2 * border);
//        if (rect.width() > 0 && rect.height() > 0) {
//            painter.setRenderHint(QPainter::Antialiasing);

//            // Draw the rectangle
//            painter.setBrush(Qt::gray);
//            painter.setPen(Qt::black);
//            painter.drawRoundedRect(rect, 7, 7);

//            // Fill the rectangle dynamically based on the charge level
//            qreal fillWidth = rect.width() * (AcceptedChargeInt / 100.0);
//            if (AcceptedChargeInt <= 30) {
//                painter.setBrush(Qt::red);
//            } else if (AcceptedChargeInt <= 60) {
//                painter.setBrush(Qt::yellow);
//            } else {
//                painter.setBrush(Qt::green);
//            }
//            painter.drawRect(rect.x(), rect.y(), fillWidth, rect.height());

//        }
//    }
    if (checkedVariant1)
    {
        //this->move(QPoint(0, 136));
        this->setFixedSize(280, 527);

        int border = 7;
        int rectTop = height()/2 - 2 * border; // Position the rectangle in the middle of the widget

        // Draw the rectangle
        QRectF rect(border, rectTop, width()/1.3 - 1 * border, height() / 6 - 2 * border);
        if (rect.width() > 0 && rect.height() > 0) {
            painter.setRenderHint(QPainter::Antialiasing);

            // Draw the outline
            painter.setPen(QPen(Qt::black, 4)); // black outline with 2px width
            painter.setBrush(Qt::NoBrush); // no fill
            painter.drawRoundedRect(rect, 15, 15);

            // Fill the rectangle dynamically based on the charge level
            qreal fillWidth = rect.width() * (AcceptedChargeInt / 100.0);
            if (AcceptedChargeInt <= 30) {
                painter.setBrush(QBrush(QColor(231, 24, 24, 255))); // semi-transparent red fill
            } else if (AcceptedChargeInt <= 60) {
                painter.setBrush(QBrush(QColor(227, 174, 35, 255))); // semi-transparent yellow fill
            } else {
                painter.setBrush(QBrush(QColor(0, 255, 0, 128))); // semi-transparent green fill
            }
            QRectF rect1(rect.x(), rect.y(), fillWidth, rect.height());
            painter.setPen(Qt::NoPen); // no outline for the fill
            painter.drawRoundedRect(rect1, 15, 15);
        }
//    painter.drawText(center, AcceptedChargeQString);
    painter.setFont(QFont("Ubuntu", 34, QFont::Medium));
    painter.setPen(QPen(Qt::white));
    painter.drawText(QRect(center.x() - 140, center.y() - 75, 220, 200), Qt::AlignHCenter | Qt::AlignBottom,  AcceptedChargeQString + " %");
    painter.setFont(QFont("Ubuntu", 14, QFont::Thin));
    painter.setPen(QPen(Qt::white));
//    painter.drawText(QRect(center.x() - 110, center.y() + 20, 220, 120), Qt::AlignHCenter | Qt::AlignTop,  "Заряд батареи");
}

}
