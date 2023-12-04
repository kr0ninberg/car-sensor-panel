#pragma once

#include <QWidget>
#include <QPainter>
#include "mainwindow.h"
#include <QDebug>

class WidgetZX : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetZX(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int num_lb7;

public slots:
    void ValueZX(int value);

};
