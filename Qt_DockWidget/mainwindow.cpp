#include <QTextEdit>
#include <QDockWidget>
#include <QLabel>


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget*w=new QWidget(this);
    QLabel*label=new QLabel("Dock Widget", w);
    QDockWidget *dock = new QDockWidget("Dock Widget", this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(w);

    textedit=new QTextEdit(this);

    toolbarMenu->addAction(dock->toggleViewAction());
}

MainWindow::~MainWindow() {}
