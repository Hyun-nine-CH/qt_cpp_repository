#include "widget.h"

#include <QApplication>
#include <QLineEdit>
#include <QCompleter>
#include <QFileSystemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QLineEdit *lineEdit = new QLineEdit;
    // QCompleter *completer = new QCompleter(lineEdit);
    // QFileSystemModel *model = new QFileSystemModel;
    // model->setRootPath(QDir::currentPath());
    // completer->setModel(model);
    // lineEdit->setCompleter(completer);
    // lineEdit->show();
    Widget w;
    w.show();
    return a.exec();
}
