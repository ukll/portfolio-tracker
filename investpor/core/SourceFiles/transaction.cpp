#include "investpor/core/HeaderFiles/transaction.h"

namespace investpor {

    namespace core {

        Transaction::Transaction(quint16 id) :
            transactionID(id)
        {

        }

        Transaction::~Transaction()
        {

        }

        int Transaction::getTransactionId()
        {
            return transactionID;
        }

        void Transaction::setTransactionId(quint16 id)
        {
            transactionID = id;
        }

    }

}
