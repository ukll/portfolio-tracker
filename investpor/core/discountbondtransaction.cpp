#include "investpor/core/discountbondtransaction.h"

#include <QString>
#include <QDate>

namespace investpor {

    namespace core {

        DiscountBondTransaction::DiscountBondTransaction(const Operation &op, const QString &isin, const QDate &term,
            const double &nomValue, const double &sPrice, const QDate &opDate, const quint16 &id) :
            Transaction(id), operationType(op), ISIN(isin), termDate(term),
            nominalValue(nomValue), salePrice(sPrice), operationDate(opDate)
        {

        }

    }

}
