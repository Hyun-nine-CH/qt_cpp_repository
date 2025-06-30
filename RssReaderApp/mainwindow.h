#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QNetworkReply>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void openRssFeed();
    void replyFinished(QNetworkReply*);
private:
    QComboBox *combo;
    QNetworkAccessManager *manager;
};
#endif // MAINWINDOW_H
