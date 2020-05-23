#include "tablemodel.h"

TableModel::TableModel(QObject *parent) : QSqlRelationalTableModel(parent) {}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    QVariant value = QSqlQueryModel::data(index, role);
    /*
    if (value.isValid() && role == Qt::DisplayRole) {
        if (index.column() == 0)
            return value.toString().prepend('#');
        else if (index.column() == 2)
            return value.toString();
    }
    if(role == Qt::ForegroundRole && index.column() == 1)
        return QVariant::fromValue(QColor(Qt::blue));
    if(role == Qt::BackgroundRole && index.column() == 2)
    {
        if(index.row()%3 == 0)      return QVariant::fromValue(QColor(Qt::red));
        else if(index.row()%3 == 1) return QVariant::fromValue(QColor(Qt::green));
        else                        return QVariant::fromValue(QColor(Qt::blue));
    }
    return value;
    */
    switch(role)
    {
        case Qt::BackgroundRole:
        {
            if(index.column() == 2)
            {
                if(index.row()%3 == 0)      return QVariant::fromValue(QColor(Qt::red));
                else if(index.row()%3 == 1) return QVariant::fromValue(QColor(Qt::green));
                else                        return QVariant::fromValue(QColor(Qt::blue));
            }
            break;
        }
        case Qt::ForegroundRole:
        {
            if(index.column() == 1)
                return QVariant::fromValue(QColor(Qt::blue));
            break;
        }
        case Qt::DisplayRole:
        {
            if(value.isValid())
            {
                if(index.column() == 0)
                    return value.toString().prepend('#');
                else if(index.column() == 2)
                    return value.toString();
            }
            break;
        }
        case Qt::TextAlignmentRole:
        {
           if(1==index.column())
              return QVariant (Qt::AlignVCenter | Qt::AlignLeft);
           if(2==index.column())
              return QVariant (Qt::AlignVCenter | Qt::AlignTrailing);
           return QVariant ( Qt::AlignVCenter | Qt::AlignHCenter );
           break;
        }
        default:
        {
           return value;
           break;
        }
    }
    return value;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.column() < 1 || index.column() > 4) return false;
    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
    int id = data(primaryKeyIndex).toInt();
    clear();

    bool ok;
    /*
    if (index.column() == 1) {
        ok = setFirstName(id, value.toString());
    } else {
        ok = setLastName(id, value.toString());
    }
    refresh();
    */
    return ok;
}
