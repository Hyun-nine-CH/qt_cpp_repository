#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>

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

protected:
    void keyPressEvent(QKeyEvent*) override;
    void mouseMoveEvent(QMouseEvent*e) override;

protected:
    static const int MOVE_SPEED = 3;
};
#endif // WIDGET_H
