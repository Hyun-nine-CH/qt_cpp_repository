#include "mainwindeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindEditor w;
    w.show();
    return a.exec();
}
