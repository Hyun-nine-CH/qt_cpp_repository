#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>

#include <QWidget>

class Widget : public QLabel
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void timerEvent(QTimerEvent *event) override;

public slots:
    void displayClock();
};
#endif // WIDGET_H
