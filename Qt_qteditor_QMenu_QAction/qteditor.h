#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class qteditor : public QMainWindow
{
    Q_OBJECT

public:
    qteditor(QWidget *parent = nullptr);
    ~qteditor();
};
#endif // QTEDITOR_H
