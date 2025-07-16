#include "widget.h"
#include <QtGui>
#include <QHeaderView>
#include <QDomDocument>

Widget::Widget(QWidget *parent)
    : QTreeWidget(parent) {
    QStringList labels;
    labels<<tr("Name")<<tr("Telephone No. ");
    setHeaderLabels(labels);

    header()->setSectionResizeMode(QHeaderView::Stretch);

    QFile file("Sample.xml");
    QDomDocument domDocument;
    domDocument.setContent(&file);

    QDomElement docElem=domDocument.documentElement();
    qDebug("%s", qPrintable(docElem.tagName()));
    QDomNode node=docElem.firstChild();
    while(!node.isNull()) {
        QDomElement element=node.toElement();
        if(!element.isNull()) {
            if(element.tagName()=="PhoneNumber") {
                QTreeWidgetItem *item=new QTreeWidgetItem(this);
                item->setText(0, element.attribute("Name"));
                item->setText(1, element.attribute("TelNo"));
            }
        }
        node=node.nextSibling();
    }
    resize(320, 240);
}
