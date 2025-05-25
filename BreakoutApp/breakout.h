#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QWidget>

#include <QMouseEvent>
#include <QKeyEvent>

class QLabel;

class Breakout : public QWidget {
private:

    static const int NO_OF_BRICKS=30;

    QLabel*ball;
    QLabel*paddle;
    QLabel*bricks[NO_OF_BRICKS];

protected:
    void keyPressEvent(QKeyEvent*) override;
    void mouseMoveEvent(QMouseEvent*e) override;

protected:
    static const int MOVE_SPEED = 3;

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

#endif // BREAKOUT_H
