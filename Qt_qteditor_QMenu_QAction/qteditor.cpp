#include "qteditor.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTextEdit>

qteditor::qteditor(QWidget *parent)
    : QMainWindow(parent)
{
    /*
    QTextEdit *textedit=new QTextEdit(this);
    setCentralWidget(textedit);

    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);
    QMenu *fileMenu=menubar->addMenu("&File");

    setMenuBar(menubar);

    QAction *newAct=new QAction(QIcon("new.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered()), SLOT(newFile()));

    QMenu *fileMenu=menubar->addMenu("&File");
    fileMenu->addAction(newAct);
    */
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    QAction* newAct = new QAction(QIcon("new.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered()), SLOT(newFile()));

    QMenu* fileMenuTest = menubar->addMenu("&File");
    fileMenuTest->addAction(newAct);
}

qteditor::~qteditor() {}

/*
#include "mainwindow.h"

#include <QTextEdit>
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  // QTextEdit* textedit = new QTextEdit(this);
  // setCentralWidget(textedit);

  QMenuBar* menubar = new QMenuBar(this);
  setMenuBar(menubar);

  QAction* newAct = new QAction(QIcon("new.png"), "&New", this);
  newAct->setShortcut(tr("Ctrl+N"));
  newAct->setStatusTip(tr("make new file"));
  connect(newAct, SIGNAL(triggered()), SLOT(newFile()));

  QMenu* fileMenuTest = menubar->addMenu("&File");
  fileMenuTest->addAction(newAct);

}

MainWindow::~MainWindow() {}
*/
