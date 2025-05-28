#ifndef BALL_H
#define BALL_H

#include <QLabel>
//#include <QWidget>
//#include <QPainter>

class Ball : public QLabel
{
public:
    Ball(QWidget*parent=nullptr);
};
/*
class Ball:public QWidget {
public:
    Ball(QWidget*parent=nullptr);

private:
    void paintEvent(QPaintEvent*) override;
};
*/
#endif // BALL_H
