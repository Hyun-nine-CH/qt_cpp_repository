#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QTcpSocket;
class QFile;
class QProgressDialog;
class QLabel;

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget( );

    QLabel* infoLabel;
    QTcpSocket *tcpClient;
    QFile *file;
    QString filename;
    QProgressDialog* progressDialog;
    QByteArray outBlock;
    qint64 loadSize;
    qint64 byteToWrite;
    qint64 totalSize;

    bool isSent;

private slots:
    void send( );
    void goOnSend(qint64);
    void openFile( );
    void sendData( );
};

#endif // WIDGET_H
