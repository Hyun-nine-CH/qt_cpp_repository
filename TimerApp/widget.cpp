#include "widget.h"
#include <QTimerEvent>
#include <QTimer>
#include <QTime>
Widget::Widget(QWidget *parent)
    : QLabel(parent)
{
    setText("Timer");

    int id1=startTimer(50);
    int id2=startTimer(1000);

    QTimer*timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(displayClock()));
    timer->start(1000);
    resize(90, 40);
}

Widget::~Widget() {}

void Widget::displayClock() {
    setText(QTime::currentTime().toString());
}

void Widget::timerEvent(QTimerEvent*event) {
    setText(QString::number(event->timerId()));
}
