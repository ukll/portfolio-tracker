#include "investpor/gui/goldtablemodel.h"

#include "investpor/core/util.h"

#include <QBrush>
#include <QColor>

using investpor::core::Operation;
using investpor::core::Util;

namespace investpor {

    namespace gui {

        GoldTableModel::GoldTableModel(QList<GoldTransaction> list, QObject *parent) :
            TableModel(parent), transactionList(list)
        {

        }

        void GoldTableModel::updateTransactionList(QList<core::GoldTransaction> list)
        {
            beginResetModel();

            transactionList = list;

            endResetModel();
        }

        double GoldTableModel::totalBuys() const
        {
            double buys = 0.0;

            QList<GoldTransaction>::const_iterator iter;
            for(iter = transactionList.cbegin(); iter < transactionList.cend(); ++iter)
            {
                if(Operation::BUY == iter->getOperationType())
                {
                    buys += (iter->getPrice() * iter->getAmount());
                }
            }

            return buys;
        }

        double GoldTableModel::totalSells() const
        {
            double sells = 0.0;

            QList<GoldTransaction>::const_iterator iter;
            for(iter = transactionList.cbegin(); iter < transactionList.cend(); ++iter)
            {
                if(Operation::SELL == iter->getOperationType())
                {
                    sells += (iter->getPrice() * iter->getAmount());
                }
            }

            return sells;
        }

        QVariant GoldTableModel::headerData(int section, Qt::Orientation orientation, int role) const
        {
            if(Qt::DisplayRole != role)
            {
                return QVariant();
            }

            if(Qt::Vertical == orientation)
            {
                return QVariant();
            }

            switch (section) {
            case 0:
                return QString("Gold Type");
            case 1:
                return QString("Transaction ID");
            case 2:
                return QString("Operation Type");
            case 3:
                return QString("Price");
            case 4:
                return QString("Amount");
            case 5:
                return QString("Goal Price");
            case 6:
                return QString("Date and Time");
            default:
                return QVariant();
            }
        }

        QVariant GoldTableModel::data(const QModelIndex &index, int role) const
        {
            if(Qt::TextAlignmentRole == role)
            {
                return Qt::AlignCenter;
            }

            if(Qt::BackgroundRole == role)
            {
                if(Operation::BUY == transactionList.at(index.row()).getOperationType()) {
                    return QBrush(QColor(0, 255, 0, 100));
                }
                return QBrush(QColor(255, 0, 0, 100));
            }

            if(Qt::DisplayRole != role)
            {
                return QVariant();
            }

            switch (index.column()) {
            case 0:
                return Util::goldName(transactionList.at(index.row()).getGoldType()).toUpper();
            case 1:
                return transactionList.at(index.row()).getTransactionId();
            case 2:
                return Util::operationName(transactionList.at(index.row()).getOperationType());
            case 3:
                return QString::number(transactionList.at(index.row()).getPrice(), 'f');
            case 4:
                return QString::number(transactionList.at(index.row()).getAmount(), 'f');
            case 5:
                return QString::number(transactionList.at(index.row()).getGoalPrice(), 'f');
            case 6:
                return transactionList.at(index.row()).getOperationDateTime().toString(Qt::ISODate);
            default:
                return QVariant();
            }
        }

    }

}
