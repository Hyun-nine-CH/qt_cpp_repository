#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  QWidget* qWidget = new QWidget(this);

  mdiArea = new QMdiArea(this);
  setCentralWidget(mdiArea);

  // ---------- Text Editor ----------
  // QTextEdit* textedit = new QTextEdit(this);
  QTextEdit* textedit = newFile();
  // setCentralWidget(textedit);

  // ---------- Menu bar ----------
  QMenuBar* menubar = new QMenuBar(this);
  setMenuBar(menubar);



  // ---------- Menu bar - File ----------
  QAction* fileNewMenu = new QAction(QIcon(":/asset/icon/new.png"), "&New", this);
  fileNewMenu->setShortcut(tr("Ctrl+N"));
  fileNewMenu->setStatusTip(tr("make new file"));
  connect(fileNewMenu, SIGNAL(triggered()), qApp, SLOT(New()));


  QAction* fileOpenMenu = new QAction(QIcon("Open.png"), "&Open", this);

  QAction* fileSaveMenu = new QAction(QIcon("Save.png"), "&Save", this);

  QAction* fileSaveAsMenu = new QAction(QIcon("Saveas.png"), "&Save as...", this);

  QAction* filePrintMenu = new QAction(QIcon("Print.png"), "&Print", this);

  QAction* fileQuitMenu = new QAction(QIcon(":/asset/icon/quit.png"), "&Quit", this);
  fileQuitMenu->setShortcut(tr("Ctrl+Q"));
  fileQuitMenu->setStatusTip(tr("quit file"));
  connect(fileQuitMenu, SIGNAL(triggered()), qApp, SLOT(quit()));


  QMenu* fileMenu = menubar->addMenu("&File");
  fileMenu->addAction(fileNewMenu);
  fileMenu->addAction(fileOpenMenu);
  fileMenu->addAction(fileSaveMenu);
  fileMenu->addAction(fileSaveAsMenu);
  fileMenu->addAction(filePrintMenu);
  fileMenu->addAction(fileQuitMenu);



  // ---------- Menu bar - Edit ----------
  QAction* editUndoMenu = new QAction(QIcon("Undo.png"), "&Undo", this);
  connect(editUndoMenu, SIGNAL(triggered()), textedit, SLOT(undo()));

  QAction* editRedoMenu = new QAction(QIcon("Redo.png"), "&Redo", this);
  connect(editRedoMenu, SIGNAL(triggered()), textedit, SLOT(redo()));

  QAction* editCopyMenu = new QAction(QIcon("Copy.png"), "&Copy", this);
  editCopyMenu->setShortcut(tr("Ctrl+C"));
  connect(editCopyMenu, SIGNAL(triggered()), textedit, SLOT(copy()));

  QAction* editCutMenu = new QAction(QIcon("Cut.png"), "&Cut", this);
  editCutMenu->setShortcut(tr("Ctrl+X"));
  connect(editCutMenu, SIGNAL(triggered()), textedit, SLOT(cut()));

  QAction* editPasteMenu = new QAction(QIcon("Paste.png"), "&Paste", this);
  editPasteMenu->setShortcut(tr("Ctrl+V"));
  connect(editPasteMenu, SIGNAL(triggered()), textedit, SLOT(paste()));

  QAction* editZoominMenu = new QAction(QIcon("Zoomin.png"), "&Zoom in", this);
  editZoominMenu->setShortcut(tr("Ctrl+Shift+]"));
  connect(editZoominMenu, SIGNAL(triggered()), textedit, SLOT(zoomIn()));

  QAction* editZoomoutMenu = new QAction(QIcon("Zoomout.png"), "&Zoom out", this);
  editZoomoutMenu->setShortcut(tr("Ctrl+Shift+["));
  connect(editZoomoutMenu, SIGNAL(triggered()), textedit, SLOT(zoomOut()));


  QMenu* editMenu = menubar->addMenu("&Edit");
  editMenu->addAction(editUndoMenu);
  editMenu->addAction(editRedoMenu);
  editMenu->addAction(editCopyMenu);
  editMenu->addAction(editCutMenu);
  editMenu->addAction(editPasteMenu);
  editMenu->addAction(editZoominMenu);
  editMenu->addAction(editZoomoutMenu);


  // ---------- Menu bar - Format ----------
  QMenu* formatMenu = menubar->addMenu("&Format");
  QMenu* formatFontnMenu = formatMenu->addMenu("&Font");
  QMenu* formatColorMenu = formatMenu->addMenu("&Color");
  QMenu* formatAlignMenu = formatMenu->addMenu("&Align");

  QAction* formatAlignLeftMenu = new QAction(QIcon("Lift.png"), "&Left", this);
  connect(formatAlignLeftMenu, &QAction::triggered, this, [=]{textedit->setAlignment(Qt::AlignLeft);});

  QAction* formatAlignRightMenu = new QAction(QIcon("Right.png"), "&Right", this);
  connect(formatAlignRightMenu, &QAction::triggered, this, [=]{textedit->setAlignment(Qt::AlignRight);});

  QAction* formatAlignCenterMenu = new QAction(QIcon("Center.png"), "&Center", this);
  connect(formatAlignCenterMenu, &QAction::triggered, this, [=]{textedit->setAlignment(Qt::AlignCenter);});

  QAction* formatAlignJustifyMenu = new QAction(QIcon("Justify.png"), "&Justify", this);
  connect(formatAlignJustifyMenu, &QAction::triggered, this, [=]{textedit->setAlignment(Qt::AlignJustify);});


  formatAlignMenu->addAction(formatAlignLeftMenu);
  formatAlignMenu->addAction(formatAlignRightMenu);
  formatAlignMenu->addAction(formatAlignCenterMenu);
  formatAlignMenu->addAction(formatAlignJustifyMenu);


  // ---------- Menu bar - Window ----------
  QMenu* windowMenu = menubar->addMenu("&Window");

  QAction* cascadeMenu = new QAction(QIcon("Cascade.png"), "&Cascade", this);
  windowMenu->addAction(cascadeMenu);

  QAction* tileMenu = new QAction(QIcon("Tile.png"), "&Tile", this);
  windowMenu->addAction(tileMenu);

  QAction* prevMenu = new QAction(QIcon("Prev.png"), "&Prev", this);
  windowMenu->addAction(prevMenu);

  QAction* nextMenu = new QAction(QIcon("Next.png"), "&Next", this);
  windowMenu->addAction(nextMenu);


  // ---------- Menu bar - Toolbar ----------
  QMenu* windowToolbarMenu = windowMenu->addMenu("&Toolbar");
        // ---------- File ----------
  QToolBar* fileToolBar = addToolBar("&File");
          // new
  fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  fileToolBar->addAction(fileNewMenu);
          // quit
  fileToolBar->addSeparator();
  fileToolBar->addAction(fileQuitMenu);

  windowToolbarMenu->addAction(fileToolBar->toggleViewAction());


  // ---------- Edit ----------
  addToolBarBreak();
  QToolBar* editToolBar = addToolBar("&Edit");

  editToolBar->addAction(editUndoMenu);
  editToolBar->addSeparator();
  editToolBar->addAction(editRedoMenu);
  editToolBar->addSeparator();
  editToolBar->addAction(editCopyMenu);
  editToolBar->addSeparator();
  editToolBar->addAction(editCutMenu);
  editToolBar->addSeparator();
  editToolBar->addAction(editPasteMenu);
  editToolBar->addSeparator();
  editToolBar->addAction(editZoominMenu);
  editToolBar->addSeparator();
  editToolBar->addAction(editZoomoutMenu);

  windowToolbarMenu->addAction(editToolBar->toggleViewAction());




          // ---------- widget ----------
  addToolBarBreak();
  QToolBar* formatToolbar = addToolBar("&Format");

  QFontComboBox* fontComboBox = new QFontComboBox(this);
  connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), textedit, SLOT(setCurrentFont(QFont)));

  QDoubleSpinBox* sizeSpinBox = new QDoubleSpinBox(this);
  connect(sizeSpinBox, SIGNAL(valueChanged(double)), textedit, SLOT(setFontPointSize(qreal)));


  formatToolbar->addWidget(fontComboBox);
  formatToolbar->addSeparator();
  formatToolbar->addWidget(sizeSpinBox);


  // ---------- Menu bar - Help ----------
  QMenu* helpMenu = menubar->addMenu("&Help");

  QAction* helpAboutMenu = new QAction(QIcon("helpAboutMenu.png"), "&About", this);
  helpMenu->addAction(helpAboutMenu);

  QAction* helpAboutQtMenu = new QAction(QIcon("AboutQtMenu.png"), "&About Qt", this);
  helpMenu->addAction(helpAboutQtMenu);

  QAction* helpTestMenu = new QAction(QIcon("helpTestMenu.png"), "&Test", this);
  helpMenu->addAction(helpTestMenu);


  // ---------- dock widget ----------
  QLabel* dockLabel = new QLabel("Dock Widget", qWidget);
  QDockWidget* dock = new QDockWidget("Dock Widget", qWidget);
  dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
  addDockWidget(Qt::RightDockWidgetArea, dock);
  dock->setWidget(qWidget);
  windowToolbarMenu->addAction(dock->toggleViewAction());





  // ---------- status bar ----------
  fileToolBar->addAction(fileQuitMenu);
  QStatusBar* statusbar = statusBar();
  QLabel* statusLabel = new QLabel(tr("Qt Editor"), statusbar);
  statusLabel->setObjectName("StautsLabel");
  statusbar->addPermanentWidget(statusLabel);
  statusbar->showMessage("started", 1500);


}

QTextEdit* MainWindow::newFile(){
  qDebug("Make New File");
  QTextEdit* textedit = new QTextEdit;
  mdiArea->addSubWindow(textedit);
  textedit->show();
  return textedit;
}
void MainWindow::quitFile(){
  qDebug("Quit File");
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

fileName = QFileDialog::getOpenFileName(this,
                                        tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));

void QDialog::setModal(bool modal)
QMessageBox::question(this, "QMessageBox::showQuestion()",
"Question Message",
QMessageBox::Yes |
QMessageBox::No |
QMessageBox::Cancel);                      )

void QtEditor::openFile() {
    QString filename=QFileDialog::getOpenFileName(this, "Select file to open",\
                QDir::home().dirName(), "TextFile(*.txt*.html*.c*.cpp*.h)");
    qDebug()<<filename;
}

void QtEditor::saveFile() {
    QString filename=QFileDialog::getSaveFileName(this,"Select file to save",)
}

MainWindow::~MainWindow() {}

