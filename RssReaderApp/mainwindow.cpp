#include "mainwindow.h"
#include "saveurls.h"

#include <QtWidgets>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QToolBar *toolbar=addToolBar(tr("Open"));

    combo=new QComboBox;
    ListView *Iv=new ListView;
    combo->setView(Iv);
    combo->setEditable(true);

    combo=new QComboBox;
    combo->setEditable(true);
    combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(combo, SIGNAL(activated(int)), SLOT(openRssFeed()));
    toolbar->addWidget(combo);

    QAction *act=new QAction(tr("Open RSS Feed"), this);
    act->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    connect(act,SIGNAL(triggered()),SLOT(openRssFeed()));
    toolbar->addAction(act);

    QLibrary lib("SaveUrls");
    if(!lib.isLoaded()) lib.load();
    SaveUrls *saveUrl=(SaveUrls*)lib.resolve("SaveUrls");
    QStringList urlList=saveUrl->load();
    for(int i=0; i<urlList.count(); i++)
        combo->addItem(urlList.at(i));
    if(lib.isLoaded()) lib.unload();

    if(urlList.count()==0)
        combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss");

    QSettings settings("RssReader.ini",QSettings::IniFormat);
    int size=settings.beginReadArray("rssFeeds");
    for(int i=0; i<size; i++) {
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString();
        combo->addItem(url);
    }

    settings.endArray();
    if(size==0)
        combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss:");

    manager=new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow() {

    QLibrary lib("SaveUrls");
    if(!lib.isLoaded()) lib.load();
    SaveUrls *saveUrl=(SaveUrls*)lib.resolve("SaveUrls");
    QStringList urlList;
    for (int i=0; i<combo->count(); i++)
        urlList.append(combo->itemText(i));
    saveUrl->save(urlList);
    if(lib.isLoaded()) lib.unload();

    QSettings settings("RssReader.ini",QSettings::IniFormat);
    settings.beginWriteArray("rssFeeds");
    settings.remove("");
    for(int i=0; i<combo->count(); i++) {
        settings.setArrayIndex(i);
        settings.setValue("url",combo->itemText(i));
    }
    settings.endArray();
}

void MainWindow::openRssFeed() {
    int i=combo->findText(combo->currentText());
    if(i != -1) {
        combo->setCurrentIndex(i);
    }else{
        combo->addItem(combo->currentText());
        combo->setCurrentIndex(combo->count()-1);
    }

    manager->get(QNetworkRequest(QUrl(combo->currentText())));
}

void MainWindow::replyFinished(QNetworkReply* netReply) {
    QString str(netReply->readAll());
    qDebug("%s", qPrintable(str));
}

void ListView::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Delete){
        event->accept();
        QModelIndexList I= selectedIndexes();
        if(I.length()>0) {
            model()->removeRow(I.at(0).row(), I.at(0).parent());
        }
    }else{
        QListView::keyPressEvent(event);
    }
}
