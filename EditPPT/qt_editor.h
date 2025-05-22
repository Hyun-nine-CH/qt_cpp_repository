#ifndef QT_EDITOR_H
#define QT_EDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QKeySequence>
#include <QToolBar>

#include <QFontComboBox>
#include <QDoubleSpinBox>

//#include <QToolButton>
#include <QLabel>
#include <QStatusBar>

class qt_editor : public QMainWindow
{
    Q_OBJECT

public:
    qt_editor(QWidget *parent = nullptr);
    ~qt_editor();

// 원형 슬롯
private:
    QAction *makeAction(QString icon, QString text, QString shortCut, \
                        QString toolTip, QObject* recv, const char*slot);

// 원형에서 템플릿으로만 변환
private:
    template <typename T>
    QAction *makeAction(QString icon, QString text, T shortCut, \
                        QString toolTip, QObject* recv, const char* slot);

// 템플릿이 필요한 QKeySequence tech && Lambda Func.
private:
    template <>
    QAction *makeAction(QString icon, QString text, const char* shortCut, \
                        QString toolTip, QObject* recv, const char* slot);

// 람다 함수를 메서드(함수)의 인자로 사용하려면 템플릿 필요
// 펑터는 함수나 클래스의 객체로 정의
private:
    template <typename T, typename Functor>
    QAction *makeAction(QString icon, QString text, T shortCut, \
                        QString toolTip, Functor lambda);

public slots:
    void newFile();
};

/*
void QtEditor::saveFile( ) {
    QString filename = QFileDialog::getSaveFileName(this, "Select file to save",                                                                  ".", "Text File (*.txt *.html *.c *.cpp *.h)");
    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow( )->widget( );
    windowHash.key(textedit)->setText(filename);
}
 */

#endif // QT_EDITOR_H
