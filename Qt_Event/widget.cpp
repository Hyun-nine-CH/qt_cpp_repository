#include "widget.h"
#include <QCloseEvent>

Widget::Widget(QWidget *parent)
    : QTextEdit(parent) {
    setText(tr("Hello World"));
    resize(100,30);
}

Widget::~Widget() {}

void Widget::moveEvent(QMoveEvent*) {
    setText(QString("X : %1, Y : %2").arg(x()).arg(y()));
}

void Widget::closeEvent(QCloseEvent* event) {
    event->accept(); // ignore();

}
// command i = auto sort [Qt]
/*
     *
     * accept(); bubbling 창 닫힘
     *
     * ignore(); capturing 창 안 닫힘
     *
     */
