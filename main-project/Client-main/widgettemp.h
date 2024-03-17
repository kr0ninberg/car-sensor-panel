#ifndef WIDGETTEMP_H
#define WIDGETTEMP_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QCoreApplication>
#include <QFontDatabase>

class WidgetTemp : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTemp(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int AcceptedTempInt;
    QString AcceptedTempQString;

public slots:
    void slotTemp(QString temp);

signals:
};

#endif // WIDGETTEMP_H
