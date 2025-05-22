#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QTextEdit>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QKeySequence>
#include <QString>
#include <QToolBar>
#include <QWidget>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>

#include <QFileDialog>
#include <QDialog>

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
  QMdiArea* mdiArea;
 public slots:
  QTextEdit* newFile();
  void quitFile();
};



#endif  // MAINWINDOW_H
