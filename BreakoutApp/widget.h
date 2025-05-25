#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>

class Breakout:public QWidget {
protected:
    void keyPressEvent(QKeyEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void timerEvent(QTimerEvent*) override;
    void moveObjects();

private:
    QLabel*bricks[NO_OF_BRICKS];
    int timerId;
    int xDir, yDir;
};

#endif // WIDGET_H
