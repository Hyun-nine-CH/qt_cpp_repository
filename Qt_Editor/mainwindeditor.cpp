/*
    QTextEdit *textedit=new QTextEdit(this);
    setCentralWidget(textedit);
*/
#include "mainwindeditor.h"

#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QAction>
#include <QFontDialog>
#include <QColorDialog>

MainWindEditor::MainWindEditor(QWidget *parent)
    : QMainWindow(parent)
{
    editor = new QTextEdit(this);
    setCentralWidget(editor);

    QMenuBar *menubar = menuBar();
    QMenu *editMenu = menubar->addMenu("&Edit");

    // 메뉴 구성 함수 호출
    createEditMenu();
}

MainWindEditor::~MainWindEditor() {}

void MainWindEditor::createEditMenu()
{
    QMenu *editMenu = menuBar()->addMenu("&Edit");

    auto addAction = [&](const QString &name, auto func) {
        QAction *act = new QAction(name, this);
        connect(act, &QAction::triggered, this, func);
        editMenu->addAction(act);
    };

    // 📌 기본 편집 기능
    addAction("Append", [=]() { editor->append("Appended text"); });
    addAction("Clear", [=]() { editor->clear(); });
    addAction("Copy", [=]() { editor->copy(); });
    addAction("Cut", [=]() { editor->cut(); });
    addAction("Paste", [=]() { editor->paste(); });
    addAction("Undo", [=]() { editor->undo(); });
    addAction("Redo", [=]() { editor->redo(); });
    addAction("Select All", [=]() { editor->selectAll(); });
    addAction("Scroll To Anchor", [=]() { editor->scrollToAnchor("anchorName"); });

    // 📌 텍스트 삽입
    addAction("Insert HTML", [=]() { editor->insertHtml("<b>Hello</b>"); });
    addAction("Insert PlainText", [=]() { editor->insertPlainText("Inserted Plain Text"); });

    // 📌 텍스트 설정
    addAction("Set HTML", [=]() { editor->setHtml("<i>Set HTML Content</i>"); });
    addAction("Set PlainText", [=]() { editor->setPlainText("Set plain text"); });
    addAction("Set Text", [=]() { editor->setText("Set as text"); });

    // 📌 서식 관련
    addAction("Set Alignment (Center)", [=]() { editor->setAlignment(Qt::AlignCenter); });

    addAction("Set Current Font", [=]() {
        QFont font = QFontDialog::getFont(nullptr, editor->font(), this);
        editor->setCurrentFont(font);
    });

    addAction("Set Font Family", [=]() { editor->setFontFamily("Courier New"); });
    addAction("Set Font Point Size", [=]() { editor->setFontPointSize(14); });
    addAction("Set Font Italic", [=]() { editor->setFontItalic(true); });
    addAction("Set Font Underline", [=]() { editor->setFontUnderline(true); });
    addAction("Set Font Weight (Bold)", [=]() { editor->setFontWeight(QFont::Bold); });

    // 📌 색상 관련
    addAction("Set Text Color", [=]() {
        QColor color = QColorDialog::getColor(Qt::black, this);
        if (color.isValid())
            editor->setTextColor(color);
    });

    addAction("Set Background Color", [=]() {
        QColor color = QColorDialog::getColor(Qt::yellow, this);
        if (color.isValid())
            editor->setTextBackgroundColor(color);
    });

    // 📌 확대/축소
    addAction("Zoom In", [=]() { editor->zoomIn(); });
    addAction("Zoom Out", [=]() { editor->zoomOut(); });
}
