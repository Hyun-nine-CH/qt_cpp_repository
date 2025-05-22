#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QMdiArea;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QMdiArea *mdiArea;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    QTextEdit *newFile();
};
#endif // MAINWINDOW_H
