#include "qstatus.h"
#include <QLabel>
#include <QStatusBar>
#include <QApplication>

QStatus::QStatus(QWidget *parent)
    : QMainWindow(parent)
{

    fileToolBar->addAction(quitAct);
    // 액션 초기화
    quitAct = new QAction("Quit", this);
    connect(quitAct, &QAction::triggered, qApp, &QApplication::quit);

    // 툴바 생성 및 액션 추가
    fileToolBar = addToolBar("File");
    fileToolBar->addAction(quitAct);

    QStatusBar *statusbar = statusBar();
    QLabel *statusLabel=new QLabel(tr("Qt Editor"), statusbar);
    statusLabel->setObjectName("StatusLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started", 1500);
}

QStatus::~QStatus() {}

/*
#include "qstatus.h"
#include <QLabel>
#include <QStatusBar>
#include <QApplication>

QStatus::QStatus(QWidget *parent)
    : QMainWindow(parent)
{
    // 액션 초기화
    quitAct = new QAction("Quit", this);
    connect(quitAct, &QAction::triggered, qApp, &QApplication::quit);

    // 툴바 생성 및 액션 추가
    fileToolBar = addToolBar("File");
    fileToolBar->addAction(quitAct);

    // 상태바 및 라벨 설정
    QStatusBar *statusbar = statusBar();
    QLabel *statusLabel = new QLabel(tr("Qt Editor"), statusbar);
    statusLabel->setObjectName("StatusLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started", 1500);
}

QStatus::~QStatus() {}

*/
