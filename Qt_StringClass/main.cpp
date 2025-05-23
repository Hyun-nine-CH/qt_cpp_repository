#include "widget.h"

#include <QApplication>
#include <QLabel>

#ifdef Q_OS_MACOS
#define kor(str)    QString::fromUtf8(str)
#else
#define kor(str)    QString::fromLocal8Bit(str)
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *hello = new QLabel(kor("<font color=blue>안녕<i>Qt!</i></font>"), 0);
    hello->show();
    hello->resize(75,35);
    return app.exec();
}
