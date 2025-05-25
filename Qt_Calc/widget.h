#ifndef WIDGET_H
#define WIDGET_H

#include <QVBoxLayout>
#include <QGridLayout>

#include <QWidget>
//#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>

class QLabel;
class QPushButton;
class QButtonGroup;

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel*m_label;
    QButtonGroup*buttonGroup;
    QString m_num1, m_op;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
//    QLabel *m_label;
    QVector<QPushButton*> m_buttons;
//    QString m_num1, m_op;
    bool m_isFirst;
    const qint32 WIDTH = 4;

public slots:
//    void setNum();
//    void setOp();
    void click(int id);
};
#endif // WIDGET_H
