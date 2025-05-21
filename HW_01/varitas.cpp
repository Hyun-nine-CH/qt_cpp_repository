#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "varitas.h"

varitas::varitas(QWidget *parent)
    : QMainWindow(parent)
{
    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit); // 해당함수는 QMainWindow의 멤버함수이다.
    // QTextEdit을 중앙에 위치시키는 기능을 수행한다.

    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar); // 위치 지정 멤버 함수

    QAction *newAct = new QAction(QIcon("new.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    connect(newAct, SIGNAL(triggered()), SLOT(newFile()));
    /*
    newAct가 클릭되면 newFile() 함수를 자동으로 호출하라.
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    함수 포인터 방식, 컴파일러가 오타를 체킹할 수 있음
    SLOT(), SIGNAL()은 매크로 방식이 문자열 기반이라 오타 나도 못잡음
    connect(newAct, &QAction::triggered, this, [=]() {
    newFile();});


    //"Ctrl+N"라는 문자열을 QKeySequence 객체로 변환하고,

    //    그걸 QAction에 단축키로 등록한 겁니다.
    // macOS에서는 "Ctrl+N" 대신 "⌘N"로 바뀔 수 있습니다.

    tr("&New"): 표시할 텍스트입니다. &는 단축키 Alt+N 같은 **접근키(Accelerator key)**로 사용됩니다.
    this: 	부모 객체입니다. 일반적으로 MainWindow나 현재 위젯을 넣어 메모리 관리와 시그널/슬롯 연결을 돕습니다.
    */
    QMenu *fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(newAct);
}

varitas::~varitas() {}

void varitas::newFile() {
    qDebug("Make New File");
}
