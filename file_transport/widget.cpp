#include "widget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QFileInfo>
#include <QByteArray>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    infoLabel=new QLabel("Hello, World",this);

    QPushButton* button=new QPushButton("Server Start", this);
    connect(button, SIGNAL(clicked()),SLOT(clickButton()));

    QHBoxLayout *layout=new QPushButton("Server Start", this);
    connect(button, SIGNAL(clicked()),SLOT(clickButton()));

    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(infoLabel);
    layout->addWidget(button);
    progressDialog=new QProgressDialog(0);
    progressDialog->setAutoClose(true);
    progressDialog->reset();
}

Widget::~Widget() {}

void Widget::acceptConnection() {
    infoLabel->setText(tr("Connected,preparing to receive files!"));
    receivedSocket=server->nextPendingConnection();
    connect(receivedSocket,SIGNAL(readyRead()),this,SLOT(readClient()));
}
void Widget::readClient() {
    infoLabel->setText(tr("Receiving file ..."));
    if(byteReceived==0) {
        progressDialog->reset();
        progressDialog->show();
        QDataStream in(receivedSocket);
        in>>totalSize>>byteReceived>>filename;
        progressDialog->setMaximum(totalSize);

        QFileInfo info(filename);
        QString currentFileName=info.fileName();
        newFile=new QFile(currentFileName);
        newFile->open(QFile::WriteOnly);
    }else{// Officially read the file content
            inBlock=receivedSocket->readAll();
            byteReceived+=inBlock.size();
            newFile->write(inBlock);
            newFile->flush();
    }
    progressDialog->setValue(byteReceived);

    if(byteReceived==totalSize) {
        infoLabel->setText(tr("%1 receive completed").arg(filename));
        inBlock.clear();
        byteReceived=0;
        totalSize=0;
        progressDialog->reset();
        progressDialog->hide();
        newFile->close();
        delete newFile;
    }
}
void Widget::clickButton() {
    totalSize=0;
    byteReceived=0;

    server=new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),SLOT(acceptConnection()));
    server->listen(QHostAddress::Any,8100);
    infoLabel->setText(tr("Start listening ..."));
}
