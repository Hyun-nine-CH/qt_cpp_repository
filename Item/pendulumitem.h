#ifndef PENDULUMITEM_H
#define PENDULUMITEM_H

#include <QWidget>
#include <QGraphicsItem>

class Pendulumitem : public QGraphicsItem
{
public:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*);
};
#endif // PENDULUMITEM_H
