#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QtSql>

class TableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};

#endif // TABLEMODEL_H
