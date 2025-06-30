#include "widget.h"

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QUdpSocket>
#include <QNetworkDatagram>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    infoLabel=new QLabel(this);
    QPushButton* button=new QPushButton("Send",this);
    connect(button, &QPushButton::clicked, this, &Widget::sendData);

    message=new QLineEdit(this);
    connect(message, &QLineEdit::returnPressed,this,&Widget::sendData);

    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->addWidget(infoLabel);
    layout->addStretch(1);
    layout->addWidget(message);
    layout->addWidget(button);

    m_udpSocket=new QUdpSocket(this);
    connect(m_udpSocket,&QUdpSocket::readyRead, this,&Widget::processPendingDatagrams);
    QHostAddress localAddress;
    localAddress.setAddress("225.0.02");
    m_udpSocket->bind(QHostAddress::AnyIPv4,45454,QUdpSocket::ShareAddress);
    m_udpSocket->joinMulticastGroup(localAddress);
    m_udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
} // time to Live

Widget::~Widget() {}

void Widget::sendData() {
    QByteArray data;
    data.clear();
    data.append(message->text().toStdString().data());

    QHostAddress localAddress;
    localAddress.setAddress("225.0.0.2");
    quint16 port = 45454;
    m_udpSocket->writeDatagram(data,localAddress,port);
}
void Widget::processPendingDatagrams() {
    QNetworkDatagram datagram=m_udpSocket->receiveDatagram();
    qDebug()<<"Message From::"<<datagram.senderAddress().toString();
    qDebug()<<"Port From::"<<datagram.senderPort();
    qDebug()<<"Message::"<<datagram.data();
    infoLabel->setText(datagram.data());
    m_udpSocket->flush();
}
