#include <QApplication>
#include <QPushButton>

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Quit", this);
    quit->resize(75,35);
    // quit->show();
    // QObject::
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

Widget::~Widget() {}
