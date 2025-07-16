#include "widget.h"
#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <QPushButton>

void myDebugMsg(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    switch(type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", qPrintable(msg));
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", qPrintable(msg));
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", qPrintable(msg));
        abort();
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myDebugMsg);
    QApplication a(argc, argv);
    Widget w;
    w.setObjectName("parent");
    QPushButton *quit = new QPushButton("Quit", &w);
    quit->setGeometry(75,30,62,40);
    quit->setObjectName("child");
    QObject::connect(quit, SIGNAL(clicked()),qApp,SLOT(quit()));
    w.setGeometry(86,70,200,120);
    w.show();
    w.dumpObjectTree();
    qDebug() << "여기까지 실행됨";
    return a.exec();
}
