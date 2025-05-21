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
