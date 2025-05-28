#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel*hello=new QLabel("Hello Qt!",0,Qt::FramelessWindowHint);
    hello->showMaximized();
    return a.exec();
}
