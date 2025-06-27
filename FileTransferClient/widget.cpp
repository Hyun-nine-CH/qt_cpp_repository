#include "widget.h"

#include <QTcpSocket>
#include <QFile>
#include <QByteArray>
#include <QProgressDialog>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent), isSent(false) {
    infoLabel = new QLabel("Hello, World", this);

    QPushButton* button = new QPushButton("Send", this);
    connect(button, SIGNAL(clicked( )), SLOT(sendData( )));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(infoLabel);
    layout->addWidget(button);
    tcpClient = new QTcpSocket(this);
    // When the connection is successful, start to transfer files
    connect(tcpClient, SIGNAL(connected( )), SLOT(send( )));
    connect(tcpClient, SIGNAL(bytesWritten(qint64)), SLOT(goOnSend(qint64)));

    progressDialog = new QProgressDialog(0);
    progressDialog->setAutoClose(true);
    progressDialog->reset( );
}

Widget::~Widget( ) {
    tcpClient->disconnectFromHost();
    if (tcpClient->state() == QAbstractSocket::UnconnectedState
        || tcpClient->waitForDisconnected(1000)) {
        qDebug("Disconnected!");
    }
}

void Widget::send( ) { // Send file header information
    byteToWrite = totalSize = file->size( ); // The size of the remaining data
    loadSize = 1024; // The size of data sent each time

    QDataStream out(&outBlock, QIODevice::WriteOnly);
    out << qint64(0) << qint64(0) << filename;
    // The total size is the file size plus the size of the file name and other information
    totalSize += outBlock.size( );
    byteToWrite += outBlock.size( );

    // Go back to the beginning of the byte stream to write a qint64 in front,
    //which is the total size and file name and other information size
    out.device( )->seek(0);
    out << totalSize << qint64(outBlock.size( ));
    qDebug() << totalSize << "/" << qint64(outBlock.size( )) << "/" << filename;

    tcpClient->write(outBlock); // Send the read file to the socket

    progressDialog->setMaximum(totalSize);
    progressDialog->setValue(totalSize - byteToWrite);
    progressDialog->show( );
}

void Widget::goOnSend(qint64 numBytes) { // Start sending file content
    qDebug("goOnSend");
    byteToWrite -= numBytes;	 	// Remaining data size
    outBlock = file->read(qMin(byteToWrite, numBytes));
    tcpClient->write(outBlock);
    progressDialog->setMaximum(totalSize);
    progressDialog->setValue(totalSize - byteToWrite);

    if (byteToWrite == 0) {         // Send completed
        infoLabel->setText(tr("File sending completed!"));
        progressDialog->reset( );
//        progressDialog->close();
    }
}

void Widget::openFile( ) { 	// Open the file and get the file name (including path)
    loadSize = byteToWrite = totalSize = 0;
    outBlock.clear( );

    filename = QFileDialog::getOpenFileName(this);
    if(filename.length()) {
        file = new QFile(filename);
        file->open(QFile::ReadOnly);

        infoLabel->setText(tr("file %1 is opened").arg(filename));
        progressDialog->setValue(0); // Not sent for the first time
    }
}

void Widget::sendData( ) {
    openFile( );
    // Only the first time it is sent,
    // it happens when the connection generates the signal connect
    if(!filename.length()) return;
    if (!isSent) {
        tcpClient->connectToHost(QHostAddress("127.0.0.1"), 8100);
        if (tcpClient->waitForConnected(1000))
            qDebug("Connected!");

        isSent = true;
    } else {
    // When sending for the first time, connectToHost initiates the connect signal to
    // call send, and you need to call send after the second time
        send( );
    }

    infoLabel->setText(tr("Sending file %1").arg(filename));
}
