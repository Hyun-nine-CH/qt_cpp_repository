#include "paddle.h"

#define WIDTH   50
#define HEIGHT  12

Paddle::Paddle(QWidget *parent)
    : QLabel{parent}
{
    resize(WIDTH, HEIGHT);
    setPixmap(QPixmap("paddle.png").scaled(WIDTH, HEIGHT));
}
/*
Paddle::Paddle(QWidget *parent)
    : QWidget{parent}
{
    resize(WIDTH, HEIGHT);
    setStyleSheet("background-color: rgba(0,0,0,0)"); // 투명한 배경 설정
}
void Paddle::paintEvent(QPaintEvent*e) {
    Q_UNUSED(e);

    QPainter p(this);
    p.setPen(QColor(Qt::transparent));
    p.setBrush(QColor(Qt::blue));
    p.drawRoundedRect(0,0,WIDTH,HEIGHT,5,5);
}
*/
