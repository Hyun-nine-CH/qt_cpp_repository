#ifndef MAINWINDEDITOR_H
#define MAINWINDEDITOR_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindEditor : public QMainWindow
{
    Q_OBJECT

public:
    MainWindEditor(QWidget *parent = nullptr);
    ~MainWindEditor();

private:
    QTextEdit *editor;

    void createEditMenu();
};
#endif // MAINWINDEDITOR_H

/*
private:
    template <typename T>
    QAction *makeAction(QString icon, QString text, T shortCut, \
                        QString toolTip, QObject* recv, const char* slot);
    template <>
    QAction *makeAction(QString icon, QString text, const char* shortCut, \
                        QString toolTip, QObject* recv, const char* slot);
    template <typename T, typename Functor>
    QAction *makeAction(QString icon, QString text, T shortCut,
                        QString toolTip, Functor lambda);
*/
