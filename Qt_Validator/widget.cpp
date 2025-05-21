#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QValidactor>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDoubleValidator *doubleValidator = new QDoubleValidator(this);
    // doubleValidator->setRange(10.0, 100.0, 3);
    doubleValidator->setBottom(10.0);
    doubleValidator->setTop(100.0);
    doubleValidator->setDecimals(3);

    QIntValidator *intValidator = new QIntValidator(this);
    //intValidator->setRange(13,19);
}

Widget::~Widget() {}
