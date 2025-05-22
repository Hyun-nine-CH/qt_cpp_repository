#include "qt_editor.h"

qt_editor::qt_editor(QWidget *parent)
    : QMainWindow(parent)
{
    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit);

    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

///*  // 원형 슬롯
    QAction *newAct = new QAction(QIcon("Icon_New_File.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered()),SLOT(newFile()));

    QAction *quitAct=new QAction("&Quit", this);
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
//*/

    // 질문: 맥에서는 quitAct 구현을 할 이유가 있을까?

/*  // QKeySequence 사용 시, 함수의 인자가 QString 아니어서 함수 오버로딩 또는 템플릿 필요
    QAction*newAct=makeAction("Icon_New_File.png", tr("&New"), QKeySequence::New, \
                                 tr("make new file"), this, SLOT(newFile()));

    QAction*quitAct=makeAction("Icon_Quit_File.png", tr("&Quit"), tr("Ctrl+Q"), \
                                 tr("Quit this program"), qApp, SLOT(quit()));
*/
//*/
    QMenu *fileMenu = menubar->addMenu("&File"); // addMenu() 메서드를 이용
    fileMenu->addAction(newAct);
}
/*  //원형 슬롯 본문
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
*/

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
