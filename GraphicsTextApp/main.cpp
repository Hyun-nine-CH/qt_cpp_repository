#include "graphicstext.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene *scene=new QGraphicsScene;
    scene->addRect(-10,-10,120,50);
    QGraphicsItem *item=new QGraphicsTextItem("Hello World!");
    scene->addItem(item);

    QGraphicsView *view=new QGraphicsView;
    view->setScene(scene);
    view->show();
    return app.exec();
}
