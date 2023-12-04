#pragma once

#include <QWidget>
#include <QPainter>

class WidgetST : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetST(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

};
