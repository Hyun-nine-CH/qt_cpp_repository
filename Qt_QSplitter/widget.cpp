#include "widget.h"
#include <QSplitter>
#include <QLabel>
#include <QDial>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label=new QLabel("&Value", this);
    QDial *dial1=new QDial(this);
    QDial *dial2=new QDial(this);
    label->setBuddy(dial2);

    QSplitter *splitter=new QSplitter(this);
    splitter->addWidget(label);
    splitter->addWidget(dial1);
    splitter->addWidget(dial2);

    resize(splitter->sizeHint());
}

Widget::~Widget() {}
