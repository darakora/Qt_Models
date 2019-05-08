#include "basecomboboxmodel.h"
#include <QSqlQuery>
#include <QModelIndex>

BaseComboBoxModel::BaseComboBoxModel(QObject *parent):QAbstractListModel(parent)
{
    QSqlQuery query;
    query.exec("select id, firstname from person");
    while (query.next()) {
        dataList.push_back(DataPair(query.value(0), query.value(1)));
        //qDebug() << query.value(0);
    }
    qDebug() << dataList.size();
}

QVariant BaseComboBoxModel::data(const QModelIndex &index, int role) const
{
    const DataPair& current = dataList.at(index.row());
    //return current.first;
    QVariant value;
    switch ( role )
        {
            case Qt::DisplayRole:
            {
                value = current.second;
            }
            break;

            case Qt::UserRole:
            {
                value = current.first;
            }
            break;

            default:
                break;
        }

        return value;
}

int BaseComboBoxModel::rowCount(const QModelIndex &parent) const
{
    return dataList.count();
}
