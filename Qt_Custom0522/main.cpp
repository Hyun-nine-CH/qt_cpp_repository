#include "qtedit.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtEdit w;
    w.show();
    return a.exec();
}
