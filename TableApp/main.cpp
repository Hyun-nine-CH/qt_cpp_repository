#include "tw.h"

#include <QApplication>
#include <QTableWidget>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableWidget tw(4, 3);
    for(int row=0; row<4; row++)
        for(int col=0; col<3; col++) {
            QTableWidgetItem *item=new QTableWidgetItem(QString("%1, %2").arg(row).arg(col));
            item->setIcon(QIcon(a.style()->standardIcon(QStyle::SP_ComputerIcon)));
            item->setTextAlignment(Qt::AlignCenter);
            tw.setItem(row, col, item);
        }
    tw.show();
    return a.exec();
}
