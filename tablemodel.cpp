#include "tablemodel.h"

TableModel::TableModel(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent) {}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    int row = index.row();
    int col = index.column();
    switch ( role )
    {
        case Qt::BackgroundRole:
        {
            if(true){
               //background for this row is blue
               return QVariant(QBrush (QColor(Qt::blue)));
            }
            //otherwise background is white
            return QVariant(QBrush (QColor(Qt::white)));
        }
        case Qt::DisplayRole:
        {
           //return actual content for row here, i. e. text, numbers
        }
        case Qt::TextAlignmentRole:
        {
           if(1==col)
              return QVariant ( Qt::AlignVCenter | Qt::AlignLeft );
           if(2==col)
              return QVariant ( Qt::AlignVCenter | Qt::AlignTrailing );
           return QVariant ( Qt::AlignVCenter | Qt::AlignHCenter );
        }
     }
}
