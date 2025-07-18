#include "pendulumcontroller.h"

pendulumcontroller::pendulumcontroller(QGraphicsItem *pendulum, QObject *parent):QObject(parent),m_pendulum(pendulum) {
    m_timeline.setFrameRange(-45,45);
    m_timeline.setEasingCurve(QEasingCurve::InOutQuad);
    m_timeline.setDuration(1000);
    m_timeline.setUpdateInterval(16);
    connect(&m_timeline,SIGNAL(frameChanged(int)),SLOT(slotRotateItem(int)));
    connect(&m_timeline,SIGNAL(finished()),this,SLOT(slotRestartTimeLine()),Qt::QueuedConnection);
    m_timeline.start();
}
void pendulumcontroller::slotRotateItem(int r) {
    m_pendulum->resetTransform();
    m_pendulum->setRotation(r);
}
void pendulumcontroller::slotRestartTimeLine() {
    m_timeline.toggleDirection();
    m_timeline.start();
}
