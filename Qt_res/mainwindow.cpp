#include "mainwindow.h"
#include <QTextEdit>
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mdiArea=new QMdiArea(this);
    setCentralWidget(mdiArea);
#if 0
    QTextEdit *textedit = new QTextEdit(this);
    mdiArea->addSubWindow(textedit);
# else
    QTextEdit *textedit=newFile();
#endif
}

MainWindow::~MainWindow() {}

QTextEdit *MainWindow::newFile() {
    qDebug("Make New File");
    QTextEdit *textedit=new QTextEdit;
    mdiArea->addSubWindow(textedit);
    textedit->show();
    return textedit;
}
