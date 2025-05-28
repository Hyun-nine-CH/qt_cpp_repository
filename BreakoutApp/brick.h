#ifndef BRICK_H
#define BRICK_H

#include <QLabel>
//#include <QWidget>
//#include <QPainter>

class Brick : public QLabel
{
public:
    Brick(QWidget*parent=nullptr);
};
/*
class Brick:public QWidget {
public:
    Brick(QWidget*parent=nullptr);

private:
    void paintEvent(QPaintEvent*) override;
};
*/
#endif // BRICK_H
