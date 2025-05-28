#include "ball.h"
#define RADIUS  10
Ball::Ball(QWidget *parent)
    : QLabel{parent}
{
    resize(RADIUS, RADIUS);
    setPixmap(QPixmap("ball.png"));
}
/*
Ball::Ball(QWidget *parent)
    : QWidget{parent}
{
    resize(RADIUS, RADIUS);
    setStyleSheet("background-color: rgba(0,0,0,0)"); // 투명한 배경 설정
}
void Ball::paintEvent(QPaintEvent*e) {
    Q_UNUSED(e);

    QPainter p(this);
    p.setPen(QColor(Qt::transparent));
    p.setBrush(QColor(Qt::red));
    p.drawEllipse(0,0,RADIUS,RADIUS);
}
*/
