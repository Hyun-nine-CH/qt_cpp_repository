#include "qstatus.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStatus w;
    w.show();
    return a.exec();
}
