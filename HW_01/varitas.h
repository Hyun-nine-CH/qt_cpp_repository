#ifndef VARITAS_H
#define VARITAS_H

#include <QMainWindow>

class varitas : public QMainWindow
{
    Q_OBJECT

public:
    varitas(QWidget *parent = nullptr);
    ~varitas();

public slots:
    void newFile();
};
#endif // VARITAS_H
