#include "widget.h"
#include <QPainter>
#include <QPen>
#include <QFont>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(200,200);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter *painter=new QPainter(this);
//    painter->setPen(QPen(Qt::blue, 4, Qt::SolidLine));
//    painter->drawChord(20,20,160,160,30*16,130*16);

    QPen pen=painter->pen();
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
    painter->drawText(20,20,"Hello");

    QFont font=painter->font();
    font.setPixelSize(48);
    painter->setFont(font);
    painter->drawText(rect(),Qt::AlignCenter,tr("Qt"));

    delete painter;

}
