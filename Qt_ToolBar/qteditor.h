#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QAction>

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

private:
    QAction *newAct;
    QAction *quitAct;

};
#endif // QTEDITOR_H
