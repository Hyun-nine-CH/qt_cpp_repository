#include "qt_editor.h"

qt_editor::qt_editor(QWidget *parent)
    : QMainWindow(parent)
{
//    QTextEdit *textedit = new QTextEdit(this);
    textedit = new QTextEdit(this);
    setCentralWidget(textedit);

    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

#if 0
    QAction *newAct = new QAction(QIcon("Icon_New_File.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered()),SLOT(newFile()));

    QAction *quitAct=new QAction("&Quit", this);
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
#else
    QAction *newAct=makeAction("Icon_New_File.png", "&New", "Ctrl+N", \
                                 "make new file", this, SLOT(newFile()));
#endif
    QAction *openAct=makeAction("Icon_Open_File.png", "&Open", "Ctrl+O", \
                                  "open a file", this, SLOT(openFile( )));

    QAction *saveAct=makeAction("Icon_Save_File.png", "&Save", "Ctrl+S", \
                                  "save this file", this, SLOT(saveFile()));

    QAction *saveAsAct = makeAction("Icon_SaveAs_File.png", "&Save &as...", "Ctrl+Shift+S", \
                                    "save this file as a new name", this, SLOT(saveAsFile( )));

    QAction *printAct = makeAction("Icon_Print_File.png", "&Print", "Ctrl+P", \
                                   "print this file", this, SLOT(print( )));

    QAction *quitAct = makeAction("Icon_Quit_File.png", "&Quit", "Ctrl+Q", \
                                  "quit this program", qApp, SLOT(quit( )));

    /* Edit Menu */
    QAction *undoAct = makeAction("Icon_Undo_File.png", "&Undo", "Ctrl+Z", \
                                  "Undo", textedit, SLOT(undo( )));
    QAction *redoAct = makeAction("Icon_Redo_File.png", "&Redo", "Ctrl+Shift+Z", \
                                  "Redo", textedit, SLOT(redo( )));
    QAction *copyAct = makeAction("Icon_Copy_File.png", "&Copy", "Ctrl+C", \
                                  "Copy", textedit, SLOT(copy( )));
    QAction *cutAct = makeAction("Icon_Cut_File.png", "C&ut", "Ctrl+X", \
                                 "Cut", textedit, SLOT(cut( )));
    QAction *pasteAct = makeAction("Icon_Paste_File.png", "&Paste", "Ctrl+V", \
                                   "Paste", textedit, SLOT(paste( )));
    QAction *zoomInAct = makeAction("Icon_ZoomIn_File.png", "Zoom &in", "Ctrl+=", \
                                    "Zoom In", textedit, SLOT(zoomIn( )));
    QAction *zoomOutAct = makeAction("Icon_ZoomOut_File.png", "Zoon &out", "Ctrl+-", \
                                     "Zoom Out", textedit, SLOT(zoomOut( )));

/*  // QKeySequence 사용 시, 함수의 인자가 QString 아니어서 함수 오버로딩 또는 템플릿 필요
    QAction*newAct=makeAction("Icon_New_File.png", tr("&New"), QKeySequence::New, \
                                 tr("make new file"), this, SLOT(newFile()));

    QAction*quitAct=makeAction("Icon_Quit_File.png", tr("&Quit"), tr("Ctrl+Q"), \
                                 tr("Quit this program"), qApp, SLOT(quit()));
*/
//*/
    QMenu *fileMenu = menubar->addMenu("&File"); // addMenu() 메서드를 이용
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    QMenu *editMenu = menubar->addMenu("&Edit");
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);

    /* Format Menu */
    QAction *fontAct = makeAction("Icon_Font_File.png", "&Font", "Ctrl+F", \
                                  "Font", this, SLOT(setFont( )));
    QAction *colorAct = makeAction("Icon_Color_File.png", "C&olor", "Ctrl+G", \
                                   "Color", this, SLOT(setColor( )));
    QAction *alignLeftAct = makeAction("Icon_Left_File.png", "&Left", "Ctrl+1", \
                                       "Left", this, SLOT(alignText( )));
    QAction *alignCenterAct = makeAction("Icon_Center_File.png", "&Center", "Ctrl+2", \
                                         "Center", this, SLOT(alignText( )));
    QAction *alignRightAct = makeAction("Icon_Right_File.png", "&Right", "Ctrl+3", \
                                        "Right", this, SLOT(alignText( )));
    QAction *alignJustifyAct = makeAction("Icon_Justify_File.png", "&Justify", "Ctrl+4", \
                                          "Justify", this, SLOT(alignText( )));

    QToolBar *fileToolBar = addToolBar("&File");
//    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveAsAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(printAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);

    QToolBar *editToolBar = addToolBar("&Edit");
//    editToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    editToolBar->addAction(undoAct);
    editToolBar->addAction(redoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(copyAct);
    editToolBar->addAction(cutAct);
    editToolBar->addAction(pasteAct);
    editToolBar->addSeparator();
    editToolBar->addAction(zoomInAct);
    editToolBar->addAction(zoomOutAct);

    QMenu *windowMenu=menubar->addMenu("&Window");
    windowMenu->addSeparator( );
    QMenu *toolbarMenu=windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction(fileToolBar->toggleViewAction());

//    QAction *alignCenterAct=new QAction("&Center", this);
//    connect(alignCenterAct, &QAction::triggered, this, [=]{textedit->setAlignment(Qt::AlignCenter);});

    QFontComboBox*fontComboBox=new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), textedit, SLOT(setCurrentFont(QFont)));
    QDoubleSpinBox*sizeSpinBox=new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)), textedit, SLOT(setFontPointSize(qreal)));

    addToolBarBreak();
    QToolBar *formatToolbar = addToolBar("&Format");

    formatToolbar->addSeparator();
    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(sizeSpinBox);

    formatToolbar->addSeparator();
    formatToolbar->addAction(fontAct);
    formatToolbar->addAction(colorAct);

    formatToolbar->addSeparator( );
    formatToolbar->addAction(alignLeftAct);
    formatToolbar->addAction(alignCenterAct);
    formatToolbar->addAction(alignRightAct);
    formatToolbar->addAction(alignJustifyAct);

    QMenu *formatMenu=menubar->addMenu("&Format");
    formatMenu->addAction(fontAct);
    formatMenu->addAction(colorAct);
/*
    formatMenu->addAction(fileToolBar->toggleViewAction());
    formatMenu->addAction(formatToolbar->toggleViewAction( ));
    formatMenu->addAction(editToolBar->toggleViewAction( ));
*/
    QMenu *alignMenu = formatMenu->addMenu("&Align");
    alignMenu->setIcon(QIcon("Icon_Align_File.png"));
    alignMenu->addAction(alignLeftAct);
    alignMenu->addAction(alignCenterAct);
    alignMenu->addAction(alignRightAct);
    alignMenu->addAction(alignJustifyAct);

    QStatusBar *statusbar=statusBar();
    QLabel*statusLabel=new QLabel(tr("Qt Editor"), statusbar);
    statusLabel->setObjectName("StautsLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started",1500);

//    QWidget* w=new QWidget(this);

    QLabel* label=new QLabel("Dock Qidget",this);
    QDockWidget* dock=new QDockWidget("Dock Widget", this);

    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(label);

//    textedit=new QTextEdit(this);

    toolbarMenu->addAction(formatToolbar->toggleViewAction( ));
    toolbarMenu->addAction(editToolBar->toggleViewAction( ));

    toolbarMenu->addAction(dock->toggleViewAction());

}

//원형 슬롯 본문
QAction *qt_editor::makeAction(QString icon, QString text, QString shortCut, \
                               QString toolTip, QObject* recv, const char*slot) {
    QAction *act=new QAction(text,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()),recv, slot);
    return act;
}

/*
// 그냥 템플릿 특수화 원형
template <typename T>
QAction *qt_editor::makeAction(QString icon, QString text, T shortCut, \
                               QString toolTip, QObject* recv, const char*slot) {
    QAction *act=new QAction(text,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()),recv, slot);
    return act;
}
*/

// 단축키를 문자열로 입력 받으면 동작이 안될 때가 있음
// const char*를 QString 클래스나 Object::tr() 메서드로 QString형으로 변환
/*
template <>
QAction *qt_editor::makeAction(QString icon, QString text, const char* shortCut, \
                               QString toolTip, QObject* recv, const char*slot) {
    QAction *act=new QAction(text,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(QString(shortCut));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()),recv, slot);
    return act;
}
*/
/*
template <typename T, typename Functor>
QAction *qt_editor::makeAction(QString icon, QString text, T shortCut, \
                               QString toolTip, Functor lambda) {
    QAction *act=new QAction(text,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    QKeySequence QKeySequence(shortCut);
    act->setShortcut(QKeySequence);
    act->setStatusTip(toolTip);
    act->setToolTip(toolTip);
    connect(act, &QAction::triggered, this, lambda);
    return act;
}
*/
qt_editor::~qt_editor() {}

void qt_editor::newFile() {
    qDebug("Make New File");
}
void qt_editor::openFile( ) {
    qDebug("Open a File");
}
void qt_editor::saveFile( ) {
    qDebug("Save this File");
}
void qt_editor::saveAsFile( ) {
    qDebug("Save this File as a new name");
}
void qt_editor::print( ) {
    qDebug("print this File");
}

void qt_editor::undo() { qDebug("Undo"); }
void qt_editor::redo() { qDebug("Redo"); }
void qt_editor::copy() { qDebug("Copy"); }
void qt_editor::cut() { qDebug("Cut"); }
void qt_editor::paste() { qDebug("Paste"); }
void qt_editor::zoomIn() { qDebug("Zoom In"); }
void qt_editor::zoomOut() { qDebug("Zoom Out"); }
void qt_editor::setFont() { qDebug("Set Font"); statusBar()->showMessage("Set Font"); }
void qt_editor::setColor() { qDebug("Set Color"); statusBar()->showMessage("Set Color"); }
void qt_editor::alignText() {
    qDebug("Align Text");
    QAction *action = static_cast<QAction*>(sender( ));
    if(action->text( ) == "&Left")
        textedit->setAlignment(Qt::AlignLeft); // <- 지역변수 textedit을 멤버변수로 전환, 헤더에 따로 클래스를 만들어 메모리 할당을 미리 해둠
    else if(action->text( ) == "&Center")
        textedit->setAlignment(Qt::AlignCenter);
    else if(action->text( ) == "&Right")
        textedit->setAlignment(Qt::AlignRight);
    else if(action->text( ).contains("Justify", Qt::CaseInsensitive))
        textedit->setAlignment(Qt::AlignJustify);
}
void qt_editor::setCurrentFont(const QFont& font) { qDebug() << "Set current font:" << font.family(); }
void qt_editor::setFontPointSize(qreal pointSize) { qDebug() << "Set font size:" << pointSize; }
void qt_editor::setFontWidget() { qDebug("Set Font Widget"); }
void qt_editor::selectWindow() { qDebug("Select Window"); }
void qt_editor::closeWindow() { qDebug("Close Window"); }
void qt_editor::about() { qDebug("About"); }
