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

    bool checkedVariant1;
    bool checkedVariant2;

public slots:
    void slotRight();
    void slotVariant1(bool checked);
    void slotVariant2(bool checked);

signals:
};

#endif // WIDGETRIGHT_H
