#ifndef WIDGETTEMP_H
#define WIDGETTEMP_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetTemp : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTemp(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int count = -10;
    int i = 0;
    int AcceptedTempInt;
    QString AcceptedTempQString;
    QVector <QRect*> Rects;

public slots:
    void slotTemp(QString temp);

signals:
};

#endif // WIDGETTEMP_H
