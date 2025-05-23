#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>

class Widget : public QTextEdit {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void moveEvent(QMoveEvent*) override;
    void closeEvent(QCloseEvent*) override;

};
/*
bool Widget::event(QEvent* e) {
    if(e->type()==QEvent::KeyPress) {
        QKeyEvent* ke=dynamic_cast<QKeyEvent*>(e);
        qDebug()<<ke->text();
        if(ke->key()==Qt::Key_Tab) { // 독자적인 Tab 키 처리
            ke->accept();
            return true;
        }
    } else if (e->type()>=QEvent::User) { // Custom 이벤트 처리
        qDebug()<<"User Event:"<<e->type();
    }
    return QObject::event(e);
}
*/
#endif // WIDGET_H
