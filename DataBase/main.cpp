#include "widget.h"

#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>

static bool createConnection() {
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("person.db");
//    db.setDatabaseName(":memory:");
    if(!db.open()) return false;

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person(id INTEGER Primary Key, "
               "firstname VARCHAR(20) NOT NULL, lastname VARCHAR(20));");
    query.exec("INSERT INTO person VALUES(101, 'Yongsu', 'Kang');");
    query.exec("INSERT INTO person(firstname, lastname) VALUES('Soomi', 'Kim')");
    query.exec("INSERT INTO person(firstname, lastname) VALUES "
               "('Jia', 'Lee'), ('YoungJin', 'Suh'), ('YoungHwa', 'Ryu');");
    return true;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection()) return 1;

//    QSqlQueryModel queryModel1;
//    queryModel1.setQuery("select *from person");
//    queryModel1.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
//    queryModel1.setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
//    queryModel1.setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));

    QSqlTableModel queryModel;
    queryModel.setTable("person");
//    queryModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
    queryModel.select();

    QSqlRecord rec=queryModel.record();
    qDebug()<<"Number of columns:"<<rec.count();
    int nameCol=rec.indexOf("firstname");
    for(int i=0; i<queryModel.rowCount(); ++i){
        QSqlRecord r=queryModel.record(i);
        qDebug()<<r.value(nameCol).toString();
    }

    QSqlQuery query("SELECT MAX(id) FROM person;");
    int idCol = rec.indexOf("id");
    query.exec();
    while (query.next())
        qDebug()<<query.value(idCol).toInt();

    QTableView *tableview=new QTableView;
    tableview->setModel(&queryModel);
    tableview->setWindowTitle(QObject::tr("Query Model"));
    tableview->show();

    return app.exec();
}
