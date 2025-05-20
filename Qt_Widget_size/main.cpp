//#include "widget.h"
#include <QLabel> // 보여주는 위젯
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel hello("<font color=blue>"
                 "Hello <i>Qt!</i></font>",nullptr); // 역슬래쉬 안써도 컴파일이 알아서 출력해줌
    hello.resize(75,35); // set- (x) re- (o)
    hello.show();
//    Widget w;
//    w.show();
    return a.exec();
}
