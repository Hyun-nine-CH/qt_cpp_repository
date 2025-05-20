#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

signals:
    void clicked();

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void slotQuit();

};
#endif // WIDGET_H
