#ifndef QTEDIT_H
#define QTEDIT_H

#include <QMainWindow>

class QTextEdit;

class QtEdit : public QMainWindow
{

    Q_OBJECT

private:
    QTextEdit *textedit;

public:
    QtEdit(QWidget *parent = nullptr);
    ~QtEdit();

public slots:
    void alignText();
};
#endif // QTEDIT_H
