#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>
class QLabel;
class breakOut : public QWidget
{
    Q_OBJECT

public:
    breakOut(QWidget *parent = nullptr);
    ~breakOut();

private:
    static const int NO_OF_BRICKS=30;

    QLabel*ball;
    QLabel*paddle;
    QLabel*bricks[NO_OF_BRICKS];
    int timerId;
    int xDir, yDir;

    QLabel *scoreLabel;
    QLabel *messageLabel;
    int score;

protected:
    void keyPressEvent(QKeyEvent*) override;
    void mouseMoveEvent(QMouseEvent*e) override;
    void timerEvent(QTimerEvent*) override;
    void moveObjects();
    void checkCollision();

protected:
    static const int MOVE_SPEED=3;
};
#endif // BREAKOUT_H
