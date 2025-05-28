#ifndef PADDLE_H
#define PADDLE_H

#include <QLabel>
//#include <QWidget>
//#include <QPainter>

class Paddle : public QLabel
{
public:
    Paddle(QWidget*parent=nullptr);
};
/*
class Paddle:public QWidget {
public:
    Paddle(QWidget*parent=nullptr);

private:
    void paintEvent(QPaintEvent*) override;
};
*/
#endif // PADDLE_H
