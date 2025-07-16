#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidget>

class Widget : public QTreeWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
};
#endif // WIDGET_H
