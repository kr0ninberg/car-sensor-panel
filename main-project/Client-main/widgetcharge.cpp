#include "widgetcharge.h"

WidgetCharge::WidgetCharge(QWidget *parent)
    : QWidget{parent}
{}

void WidgetCharge::slotCharge(QString charge)
{
    count += 1;
    if (count == 100){count = 0;}
    qDebug() << "Charge accepted" << charge;
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

//    int idFont = QFontDatabase::addApplicationFont(QCoreApplication::applicationDirPath() + "/Jura-Medium.woff");
//    QString juraFont = QFontDatabase::applicationFontFamilies(idFont).at(0);

    QPoint center = painter.viewport().center();
    painter.drawRect(painter.viewport());

    painter.setPen(QPen(QColor(15, 89, 201), 12, Qt::SolidLine, Qt::RoundCap));

    painter.drawArc(QRect(10, 10, 260, 260), 1440 , count*57.6);
    painter.drawText(center, AcceptedChargeQString);
}
