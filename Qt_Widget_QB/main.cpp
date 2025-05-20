#include <QApplication>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QLabel hello("<font color=blue>Hello <i>Qt!</i> </font>", &w);
    hello.resize(75, 35);
    QPushButton quit("Quit", &w);
    quit.move(10,40);
    quit.resize(75,35);

    QObject::connect(&quit, &QPushButton::clicked,
                     &hello, [&](){hello.setText("<b>Hi</b>");});
    w.show();

    return a.exec();
}
