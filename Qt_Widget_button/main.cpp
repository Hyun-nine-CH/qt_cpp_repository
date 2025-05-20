//#include "widget.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
// Qt_Widget_

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel hello("<font color=blue>"
                 "Hello <i>Qt!</i></font>",nullptr);
    QPushButton quit("Quit", 0);
    quit.resize(75,35);
    quit.show();
//    Widget w;
//    w.show();
    return a.exec();
}
