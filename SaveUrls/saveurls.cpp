#include "saveurls.h"
#include <QSettings>

SaveUrls::SaveUrls() {
    qDebug("SaveUrl");
}

void SaveUrls::save(QStringList urlList) {
    QSettings settings("rssFeeds.ini",QSettings::IniFormat);
    settings.beginWriteArray("rssFeeds");
    settings.remove("");
    for (int i=0; i<urlList.count(); i++) {
        settings.setArrayIndex(i);
        settings.setValue("url",urlList.at(i));
    }
    settings.endArray();
}

QStringList SaveUrls::load() {
    QStringList urlList;
    QSettings settings("rssFeeds.ini",QSettings::IniFormat);
    int size=settings.beginReadArray("rss Feeds");
    for(int i=0; i<size; i++) {
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString();
        urlList.append(url);
    }
    settings.endArray();
    return urlList;
}
