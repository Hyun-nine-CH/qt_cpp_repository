#ifndef GRAPHICSTEXT_H
#define GRAPHICSTEXT_H

#include <QWidget>

class graphicsText : public QWidget
{
    Q_OBJECT

public:
    graphicsText(QWidget *parent = nullptr);
    ~graphicsText();
};
#endif // GRAPHICSTEXT_H
