#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QUdpSocket;
class QLabel;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void sendData();
    void processPendingDatagrams();

    QLabel* infoLabel;
    QLineEdit *message;
    QUdpSocket *m_udpSocket=nullptr;
};
#endif // WIDGET_H
