#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit);

    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

#if 0
    QAction *newAct = new QAction(QIcon("new.png"),"&New",this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered()), SLOT(newFile()));
#else
    QAction *newAct = makeAction("new.png", "&New", "Ctrl"\
                                 "make new file", this, SLOT(newFile()));

#elseif
    QAction
}

MainWindow::~MainWindow() {}
/*
 * 사용자 정의 슬롯을 위한 3가지 조건
 * 1. 부모 클래스는 QObj 클래스를 직/간접적으로 상속
 * 2. 헤더파일(.h)에서 클래스의 선언 부분 아래에 QObj 지시어 필요
 * 3. 클래스 내에 시그널과 슬롯을 선언
 *  시그널을 선언할 뿐 구현할 필요가 없다
 *
 *  람다함수는 슬롯을 만들 필요 없다
 *
 *
 *
 *
 *
 *
 * /
