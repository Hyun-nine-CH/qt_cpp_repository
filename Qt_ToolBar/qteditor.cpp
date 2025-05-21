#include "qteditor.h"
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>
#include <QAction>
#include <QApplication>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *menubar = menuBar();

    newAct = new QAction("New", this);
    quitAct = new QAction("Quit", this);
    connect(quitAct, &QAction::triggered, qApp, &QApplication::quit);

    QMenu *fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(quitAct);

    QToolBar *fileToolBar=addToolBar("&File");

    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);

    QMenu *windowMenu = menubar->addMenu("&Window");
    QMenu *toolbarMenu = windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction(fileToolBar->toggleViewAction());
}

QtEditor::~QtEditor() {}
