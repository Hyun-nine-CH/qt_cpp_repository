/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    template <typename T> // 1.
    QAction *makeAction(QString icon, QString text, T shortCut, \
                        QString toolTip, QObject* recv, const char* slot);

    template <> // 2.
    QAction *makeAction(QString icon, QString text, \
                        const char* shortCut, QString toolTip, \
                        QObject* recv, const char* slot);

    template <typename T, typename Functor> // 3.
    QAction *makeAction(QString icon, QString text, T shortCut,
                        QString toolTip, Functor lambda);

public slots:
    void newFile();

};

#endif // MAINWINDOW_H
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>

class QAction;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    //  template <typename T>
    QAction* makeAction(QString icon, QString text, QString shortCut, QString toolTip, QObject* recv, const char* slot);
    //  template <typename T, typename Functor>
    //  QAction* makeAction(QString icon, QString text, T shortCut, QString toolTip, Functor lambda);
public slots:
    void newFile();
    void quitFile();
};

#endif  // MAINWINDOW_H
