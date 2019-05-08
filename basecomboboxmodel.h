#ifndef BASECOMBOBOX_H
#define BASECOMBOBOX_H
#include <QAbstractListModel>
#include <QPair>
#include <QVariant>
#include <QList>
#include <QDebug>

class BaseComboBoxModel : public QAbstractListModel
{
      Q_OBJECT

public:
    using DataPair = QPair<QVariant, QVariant>;
    BaseComboBoxModel(QObject *parent = nullptr);
    virtual QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    virtual int rowCount( const QModelIndex & parent = QModelIndex() ) const;
    QList<DataPair> dataList;
};

#endif // BASECOMBOBOX_H
