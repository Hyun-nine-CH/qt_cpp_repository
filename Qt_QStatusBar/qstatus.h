#ifndef QSTATUS_H
#define QSTATUS_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>

#include <QMainWindow>

class QStatus : public QMainWindow
{
    Q_OBJECT

public:
    QStatus(QWidget *parent = nullptr);
    ~QStatus();

private:
    QToolBar *fileToolBar;
    QAction *quitAct;
};
#endif // QSTATUS_H
