#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget // QWidget의 상속을 받은 widget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr); // C++ 11은 0 아니고 nullptr
    ~Widget();
};
#endif // WIDGET_H
