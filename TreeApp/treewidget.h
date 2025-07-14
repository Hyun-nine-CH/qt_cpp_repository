#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>

class treeWidget : public QWidget
{
    Q_OBJECT

public:
    treeWidget(QWidget *parent = nullptr);
    ~treeWidget();
};
#endif // TREEWIDGET_H
