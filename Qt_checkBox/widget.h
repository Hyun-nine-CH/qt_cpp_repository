#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QCheckBox;
class QButtonGroup;

class Widget : public QWidget
{
private:
    QCheckBox *checkBox[4];
    QButtonGroup *buttonGroup;

public slots:
    void selectButton(int id);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
