#include <QLabel>
#include "breakout.h"

#define WIDTH   50
#define HEIGHT  12
#define SCR_WIDTH   300
#define SCR_HEIGHT  400

#include <QApplication>

Breakout::Breakout(QWidget *parent)
    : QWidget(parent), xDir(1), yDir(-1) {
    ball=new QLabel(this);
    ball->setGeometry(SCR_WIDTH*0.8, SCR_HEIGHT*0.875, 10, 10);
    ball->setStyleSheet("QLabel{ background-color:red; border-radius: 5px; }");

    paddle=new QLabel(this);
    paddle->setGeometry(SCR_WIDTH*0.7, SCR_HEIGHT*0.9, WIDTH, HEIGHT);
    paddle->setStyleSheet("QLabel { background-color:blue; }");

    for(int y=0, i=0; y<5; y++)
        for(int x=0; x<6; x++, i++) {
            bricks[i] = new QLabel(this);
            bricks[i]->setStyleSheet("QLabel { background-color:pink;"
                                     "border: 1px solid black }");
            bricks[i]->setGeometry(x*WIDTH, y*HEIGHT+30, WIDTH, HEIGHT);
        }
    resize(SCR_WIDTH, SCR_HEIGHT);

    setMouseTracking(true);

    timerId=startTimer(10);
}

Breakout::~Breakout() {
    delete ball;
    delete paddle;

    for(int i=0; i<NO_OF_BRICKS; i++) {
        delete bricks[i];
    }
}

void Breakout::keyPressEvent(QKeyEvent*e) {
    switch (e->key()) {
    case Qt::Key_Left:
        paddle->move(paddle->x()-MOVE_SPEED, paddle->y());
        break;
    case Qt::Key_Right:
        paddle->move(paddle->x()+MOVE_SPEED, paddle->y());
        break;
    case Qt::Key_Escape:
        qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(e);
    }
} // 키보드 이동에도 경계 검사 추가하기

void Breakout::mouseMoveEvent(QMouseEvent*e) {
    int x = e->pos().x();
    x = (x<0)? 0 : (x+WIDTH>width())? width()-WIDTH:x;
    paddle->move(x, paddle->y());
}

void Breakout::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    moveObjects();
}

void Breakout::moveObjects() {
    ball->move(ball->x()+xDir,ball->y()+yDir);

    if((ball->x()<=0) || (ball->x()+10>=SCR_WIDTH)) {
        xDir*=-1;
    }
    if (ball->y()<=0) yDir=1;
}

// Protected Functions
