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

    bool checkedVariant1;
    bool checkedVariant2;

    int count = -10;
    int count_2 = 0;
    int i = 0;
    int AcceptedTempInt;
    QString AcceptedTempQString;
    QVector <QRect*> Rects;

public slots:
    void slotTemp(QString temp);
    void slotVariant1(bool checked);
    void slotVariant2(bool checked);
signals:
};

#endif // WIDGETTEMP_H
