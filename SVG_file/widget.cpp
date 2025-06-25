#include <QSvgRenderer>
#include <QPainter>

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300,300);
    buffer=QImage(size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&buffer);
    painter.setViewport(0,0,width(),height());
    painter.eraseRect(0,0,width(),height());

    QString filename("sample.svg");
    QSvgRenderer svgr(filename);
    svgr.render(&painter);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0,0,buffer);
}
