#include "mainwindow.h"
#include "saveurls.h"

#include <QtWidgets>
#include <QSettings>

#include <QDomDocument>
#include <QDomNodeList>

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

    listView=new QListView;
    connect(listView, SIGNAL(doubleClicked(QModelIndex)),
            SLOT(listViewDoubleClicked(QModelIndex)));
    model=new QStandardItemModel(0,1,this);
    listView->setModel(model);

    QSplitter *splitter=new QSplitter;
    splitter->addWidget(listView);
    this->setCentralWidget(splitter);

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

    openRssFeed();
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

void MainWindow::listViewDoubleClicked(const QModelIndex &index) {
    qDebug("listViewDoubleClicked");
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

    QVariant vt=netReply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if(!vt.isNull()) {
        qDebug()<<"Redirected to:"<<vt.toUrl().toString();
        QNetworkReply *reply=manager->get(QNetworkRequest(vt.toUrl()));
        connect(reply,SIGNAL(downloadProgress(qint64,qint64)), SLOT(downloadProgress(qint64,qint64)));
    }else{
        QDomDocument doc;
        QString error;
        if(!doc.setContent(str,false,&error)) {
            qDebug("Error");
        }else{
            QDomElement docElem=doc.documentElement();
            QDomNodeList nodeList=docElem.elementsByTagName("item");

            model->clear();
            model->insertColumn(0);
            for (int i=0; i<nodeList.length(); i++) {
                QDomNode node = nodeList.item(i);
                QDomElement e=node.toElement();
                QString strTitle=
                    e.elementsByTagName("title").item(0).firstChild().nodeValue();
                QString strLink=
                    e.elementsByTagName("link").item(0).firstChild().nodeValue();
                QString strDescription=
                    e.elementsByTagName("description").item(0).firstChild().nodeValue();
                QString strToolTip="<b>"+strTitle+"</b>"+"<br/><br/>"+strDescription+"<br /><br />"+strLink;
                model->insertRows(model->rowCount(), 1);
                QModelIndex index=model->index(model->rowCount() -1, 0);
                model->setData(index, strTitle, Qt::DisplayRole);
                model->setData(index, style()->standardIcon(QStyle::SP_FileIcon), Qt::DecorationRole);
                model->setData(index, strToolTip, Qt::ToolTipRole);
                model->setData(index, strLink, Qt::UserRole);
                model->itemFromIndex(index)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            }
        }
    }
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
