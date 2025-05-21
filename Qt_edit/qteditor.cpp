#include "qteditor.h"

#include <QTextEdit>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QKeySequence>
#include <QString>
#include <QToolBar>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {

    // Menu bar
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    // File
    QAction* fileNewMenu = new QAction(QIcon("New.png"), "&New", this);
    fileNewMenu->setShortcut(tr("Ctrl+N"));
    fileNewMenu->setStatusTip(tr("make new file"));
    //connect(fileNewMenu, SIGNAL(triggered()), qApp, SLOT(New()));
    // connect()로 시그널-슬롯 연결을 하려 했지만 qApp->New() 슬롯은 존재하지 않아 잘못된 연결입니다 (실행 시 오류).
    connect(fileNewMenu, &QAction::triggered, this, &MainWindow::newFile);

    QAction* fileOpenMenu = new QAction(QIcon("Open.png"), "&Open", this);
    QAction* fileSaveMenu = new QAction(QIcon("Save.png"), "&Save", this);
    QAction* fileSaveAsMenu = new QAction(QIcon("Saveas.png"), "&Save as...", this);
    QAction* filePrintMenu = new QAction(QIcon("Print.png"), "&Print", this);

    QAction* fileQuitMenu = new QAction(QIcon("Quit.png"), "&Quit", this);
    //fileNewMenu->setShortcut(tr("Ctrl+Q"));
    //fileNewMenu->setStatusTip(tr("quit file"));
    //connect(fileQuitMenu, SIGNAL(triggered()), qApp, SLOT(quit()));
    fileQuitMenu->setShortcut(tr("Ctrl+Q"));
    fileQuitMenu->setStatusTip(tr("Quit the application"));
    connect(fileQuitMenu, &QAction::triggered, qApp, &QApplication::quit);


    QMenu* fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(fileNewMenu);
    fileMenu->addAction(fileOpenMenu);
    fileMenu->addAction(fileSaveMenu);
    fileMenu->addAction(fileSaveAsMenu);
    fileMenu->addAction(filePrintMenu);
    fileMenu->addAction(fileQuitMenu);


    // Edit
    QAction* editUndoRedoMenu = new QAction(QIcon("Undo/Redo.png"), "&Undo / Redo", this);
    QAction* editCopyMenu = new QAction(QIcon("Copy.png"), "&Copy", this);
    QAction* editCutMenu = new QAction(QIcon("Cut.png"), "&Cut", this);
    QAction* editPasteMenu = new QAction(QIcon("Paste.png"), "&Paste", this);
    QAction* editZoominZoomoutMenu = new QAction(QIcon("Zoomin/Zoomout.png"), "&Zoom in / Zoom out", this);


    QMenu* editMenu = menubar->addMenu("&Edit");
    editMenu->addAction(editUndoRedoMenu);
    editMenu->addAction(editCopyMenu);
    editMenu->addAction(editCutMenu);
    editMenu->addAction(editPasteMenu);
    editMenu->addAction(editZoominZoomoutMenu);


    // Format

    // Window

    // Help


    // Toolbar
    QToolBar* fileToolBar = addToolBar("&File");
        // new
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(fileNewMenu);
        // quit
    fileToolBar->addSeparator();
    fileToolBar->addAction(fileQuitMenu);

    QMenu* windowMenu = menubar->addMenu("&Window");
    QMenu* toolbarMenu = windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction(fileToolBar->toggleViewAction());



}

// QAction* MainWindow::makeAction(){

// }

void MainWindow::newFile(){

}
void MainWindow::quitFile(){

}


// QAction* MainWindow::makeAction(
//     QString icon,
//     QString text,
//     QString shortCut,
//     QString toolTip,
//     QObject* recv,
//     const char* slot){
//   QAction* act = new QAction(text, this);
//   if(icon.length()){
//     act->setIcon(QIcon((icon)));
//   }
//   act->setShortcut(shortCut);
//   act->setStatusTip(toolTip);
//   connect(act, SIGNAL(triggered()), recv, slot);
//   return act;
// }

// QAction* MainWindow::makeAction(
//     QString icon,
//     QString text,
//     QString shortCut,
//     QString toolTip,
//     QObject* recv,
//     const char* slot){
//   QAction* act = new QAction(text, this);
//   if(icon.length()){
//     act->setIcon(QIcon((icon)));
//   }
//   act->setShortcut(shortCut);
//   act->setStatusTip(toolTip);
//   connect(act, SIGNAL(triggered()), recv, slot);
//   return act;
// }




MainWindow::~MainWindow() {}

