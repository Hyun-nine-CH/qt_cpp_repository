//#include "widget.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel hello("<font color=blue>""Hello <i>Qt!</i></font>",0);
    hello.show();
//    Widget w;
//    w.show();
    return a.exec();
}

// 전역 변수 초기화 되어 있으면 stack, 안되어 있으면 bss

// 지역변수(hello)는 stack에 위치하고 있ㅇ어 main 함수에서 빠져나가면은 소멸됨
