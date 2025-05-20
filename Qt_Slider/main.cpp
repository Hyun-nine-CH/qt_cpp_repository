//#include "widget.h"
#include <QSlider>
#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSlider *slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setTickInterval(QSlider::TicksAbove);
    slider->setStyle(QStyleFactory::create("Fusion"));
    slider->show();


//    Widget w;
//    w.show();
    return a.exec();
}

/*
QWidget w;

QProgressBar bar(&w);
bar.setGeometry(10, 10, 150, 20);

QSlider slider(&w);
slider.setGeometry(10, 40, 150, 20);
slider.serOrientation(Qt::Horizontal);

QOBject::connect(&slider, SIGNAL(valueChanged(int)), &bar, SLOT(setValue(int)));

QOBject::connect(&slider, &QSlider::valueChanged, &Bar, &QProgressBar::setValue);
*/

/*
#include <QProgressBar>
#include <QSlider>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QProgressBar bar(&w);
    bar.setGeometry(10, 10, 150, 20);

    QSlider slider(&w);
    slider.setGeometry(10, 40, 150, 20);
    slider.setOrientation(Qt::Horizontal);

    QObject::connect(&slider, SIGNAL(valueChanged(int)), &bar, SLOT(setValue(int)));

    w.show();
    return a.exec();
}
*/
