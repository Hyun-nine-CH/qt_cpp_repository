#include "pendulumitem.h"
#include "pendulumcontroller.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView *view=new QGraphicsView;
    QGraphicsScene *scene=new QGraphicsScene(view);
    view->setScene(scene);

    Pendulumitem *pendulum=new Pendulumitem;
    scene->addItem(pendulum);

    pendulumcontroller controller(pendulum);
    view->setRenderHint(QPainter::Antialiasing);
    view->setSceneRect(-150,-20,300,200);
    view->resize(320,240);
    view->show();

    return a.exec();
}
