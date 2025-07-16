#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

void sendRequest();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    sendRequest();

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    return a.exec();
}

void sendRequest() {
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr,SIGNAL(finished(QNetworkReply*)),
                     &eventLoop,SLOT(quit()));
    QNetworkRequest req( QUrl( QString("https://timeapi.io/api/Time/current/zone?timeZone=Asia/Seoul")));
    QNetworkReply*reply=mgr.get(req);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        QString strReply = (QString)reply->readAll();
        //json파싱
        qDebug() << "Response: " << strReply;
        QJsonDocument jsonResponse =
            QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObj = jsonResponse.object();

        qDebug() << "DateTime: " << jsonObj["dateTime"].toString();
        qDebug() << "Year: " << jsonObj["year"].toInt();
        qDebug() << "Month: " << jsonObj["month"].toInt();
        qDebug() << "Day: " << jsonObj["day"].toInt();
        qDebug() << "Hour: " << jsonObj["hour"].toInt();
        qDebug() << "Minute: " << jsonObj["minute"].toInt();
        qDebug() << "Seconds: " << jsonObj["seconds"].toInt();

        delete reply;
    } else {
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }
}
