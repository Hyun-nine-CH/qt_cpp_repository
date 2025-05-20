#include "widget.h"
#include <QLCDNumber>
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QLCDNumber *lcd = new QLCDNumber();

    //lcd->setBinMode();
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(2002);
//    lcd->display(0010);
    //lcd->setDigitCount(15);
    lcd->show();

    return a.exec();

}
