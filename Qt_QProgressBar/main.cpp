#include <QTextBrowser>
#include <QApplication>
#include <QUrl>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QTextBrowser*tb = new QTextBrowser();
    tb->setSource(QUrl("index.html"));
    tb->show();

    return a.exec();

}
