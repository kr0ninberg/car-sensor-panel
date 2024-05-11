#ifndef WIDGETRIGHT_H
#define WIDGETRIGHT_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QLabel>

class WidgetRight : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetRight(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

public slots:
    void slotRight();

signals:
};

#endif // WIDGETRIGHT_H
