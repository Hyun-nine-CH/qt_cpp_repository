#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton*quit = new QPushButton("&Quit",this);
    quit->resize(75,35);
    QLabel*label = new QLabel("<font color=blue>Hello Qt!</font>",this);
    label->setGeometry(10,50,75,35);
    connect(quit, SIGNAL(clicked()), this, SLOT(slotQuit()));
}

void Widget::slotQuit() {
    qDebug("slotQuit");
//    qApp->quit();
    emit clicked();
}

Widget::~Widget() {}
