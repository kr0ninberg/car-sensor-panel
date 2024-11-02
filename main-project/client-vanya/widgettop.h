#ifndef WIDGETTOP_H
#define WIDGETTOP_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QDateTime>

class WidgetTop : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTop(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int count = 15;
    int AcceptedTempInt;
    QString AcceptedTempQString;

public slots:
    void slotTop(QString temp);

signals:
};

#endif // WIDGETTOP_H
