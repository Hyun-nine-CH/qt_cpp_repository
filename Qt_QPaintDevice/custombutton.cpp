#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent)
    : QWidget(parent), m_isEntered(false), m_isHighlighted(false)
{
    resize(130, 30);
}

void CustomButton::paintEvent(QPaintEvent*) {
    QPainter painter;
    painter.begin(this);
    painter.setBrush(m_isHighlighted?(Qt::yellow):
                         (m_isEntered?(Qt::darkYellow):(Qt::lightGray)));
    painter.drawRoundedRect(this->rect(),15,15);
    painter.drawText(10,20,QString("x:%1/y:%2").arg(x()).arg(y()));
    painter.end();

    if(m_isHighlighted) {
        m_timer.stop();
        m_timer.singleShot(300,this,SLOT(update()));
        m_isHighlighted=false;
    }
}
void CustomButton::enterEvent(QEnterEvent*) {
    m_isEntered=true;
    m_isHighlighted=false;
    emit valueChanged(cnt++);
    update();
}
void CustomButton::leaveEvent(QEvent*) {
    m_isEntered=false;
    m_isHighlighted=false;
//    emit valueChanged(QString::number(cnt));
    repaint();
}
void CustomButton::mousePressEvent(QMouseEvent*) {
    //m_isEntered=false;
    m_isHighlighted=true;
    update();
    emit clicked();
}
CustomButton::~CustomButton() {}
