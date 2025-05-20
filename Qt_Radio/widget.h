#ifndef WIDGET_H
#define WIDGET_H

class QRadioButton;
class QButtonGroup;

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

    QRadioButton *radioButton[4];
    QButtonGroup *buttonGroup;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
