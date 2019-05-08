#include "database.h"
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

bool DataBase::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return  db.open();
}

void DataBase::createTables()
{
    QSqlQuery query;
    query.exec("create table person (id int primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("create table items (id int primary key,"
                                                "imagefile int,"
                                                "itemtype varchar(20),"
                                                "description varchar(100))");
}

void DataBase::fillDatabase()
{
    QSqlQuery query;
    query.exec("insert into person values(101, 'Danny', 'Young')");
    query.exec("insert into person values(102, 'Christine', 'Holand')");
    query.exec("insert into person values(103, 'Lars', 'Gordon')");
    query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");
    query.exec("create table items (id int primary key,"
                                                "imagefile int,"
                                                "itemtype varchar(20),"
                                                "description varchar(100))");
    query.exec("insert into items "
                  "values(0, 0, 'Qt',"
                  "'Qt is a full development framework with tools designed to "
                  "streamline the creation of stunning applications and  "
                  "amazing user interfaces for desktop, embedded and mobile "
                  "platforms.')");
    query.exec("insert into items "
                  "values(1, 1, 'Qt Quick',"
                  "'Qt Quick is a collection of techniques designed to help "
                  "developers create intuitive, modern-looking, and fluid "
                  "user interfaces using a CSS & JavaScript like language.')");
    query.exec("insert into items "
                  "values(2, 2, 'Qt Creator',"
                  "'Qt Creator is a powerful cross-platform integrated "
                  "development environment (IDE), including UI design tools "
                  "and on-device debugging.')");
    query.exec("insert into items "
                  "values(3, 3, 'Qt Project',"
                  "'The Qt Project governs the open source development of Qt, "
                  "allowing anyone wanting to contribute to join the effort "
                  "through a meritocratic structure of approvers and "
               "maintainers.')");
}

QStringList DataBase::getPersonList()
{
    QSqlQuery query;
    QStringList result;
    query.exec("select firstname, lastname from person");
    while (query.next()) {
    QString temp = query.value(0).toString()+query.value(1).toString();
    qDebug() << temp;
    result.push_back(temp);
    }
    return result;
}

