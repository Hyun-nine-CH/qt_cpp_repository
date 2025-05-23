#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    static const int NO_OF_BRICKS=30;

    QLabel*ball;
    QLabel*paddle;
    QLabel*bricks[NO_OF_BRICKS];
};
#endif // WIDGET_H
