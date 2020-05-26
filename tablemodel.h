#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QtSql>

class TableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int);

    bool setTitle(int id, const QString &title);

    void refresh();
};

#endif // TABLEMODEL_H
