#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QWebEngineView *view=new QWebEngineView();
    view->load(QUrl("http://naver.com"));
    view->show();
    return a.exec();
}
