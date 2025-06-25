#ifndef SCRATCHPAD_H
#define SCRATCHPAD_H

#include <QWidget>

class ScratchPad : public QWidget
{
    Q_OBJECT

public:
    explicit ScratchPad(QWidget *parent=0);
//    ScratchPad(QWidget *parent = nullptr);
    ~ScratchPad();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void resizeImage(QImage *image, const QSize &newSize);
    bool modified;
    QImage image;
    QPointF prevPos;
    QColor paintColor;
    qreal paintSize;
};
#endif // SCRATCHPAD_H
