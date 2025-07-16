#include "widget.h"

#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebEngineView *view=new QWebEngineView();
    view->load(QUrl("http://valentis.pe.kr"));
    view->show();
    return a.exec();
}
