#include "brick.h"

#define WIDTH   50
#define HEIGHT  12

Brick::Brick(QWidget *parent)
    : QLabel{parent}
{
    resize(WIDTH, HEIGHT);
    setPixmap(QPixmap("brick.png").scaled(WIDTH, HEIGHT));
}
/*
Brick::Brick(QWidget *parent)
    : QWidget{parent}
{
    resize(WIDTH, HEIGHT);
    setStyleSheet("background-color: rgba(0,0,0,0)"); // 투명한 배경 설정
}
void Brick::paintEvent(QPaintEvent*e) {
    Q_UNUSED(e);

    QPainter p(this);
    p.setBrush(QColor(Qt::cyan));
    p.drawRect(0,0,WIDTH,HEIGHT);
}
*/
