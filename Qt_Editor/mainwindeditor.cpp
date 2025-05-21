#include "mainwindeditor.h"
#include <QTextEdit>
MainWindEditor::MainWindEditor(QWidget *parent)
    : QMainWindow(parent)
{
    QTextEdit *textedit=new QTextEdit(this);
    setCentralWidget(textedit);
}

MainWindEditor::~MainWindEditor() {}
