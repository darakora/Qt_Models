#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "util.h"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    static bool createConnection();
    static void createTables();
    static void fillDatabase();
    static QStringList getPersonList();

signals:

public slots:
};

#endif // DATABASE_H
