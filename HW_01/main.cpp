#include "varitas.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    varitas w;
    w.show();
    return a.exec();
}
