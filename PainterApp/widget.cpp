#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(200,200);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter *painter=new QPainter(this);
    painter->setPen(QPen(Qt::blue, 4, Qt::SolidLine));
    painter->drawChord(20,20,160,160,30*16,130*16);
    delete painter;
}
