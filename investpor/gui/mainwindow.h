#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "investpor/core/portfolioxml.h"
#include "investpor/gui/cryptocurrencytablemodel.h"
#include "investpor/gui/discountbondtablemodel.h"
#include "investpor/gui/exchangetablemodel.h"
#include "investpor/gui/fundtablemodel.h"
#include "investpor/gui/goldtablemodel.h"

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

using investpor::core::PortfolioXML;

namespace investpor {

    namespace gui {

        class MainWindow : public QMainWindow
        {
            Q_OBJECT

        public:
            explicit MainWindow(QWidget *parent = 0);
            ~MainWindow();


        private:
            Ui::MainWindow *ui;

            PortfolioXML *portfolio;
            CryptocurrencyTableModel *cryptoCurrencyModel;
            DiscountBondTableModel *discountBondModel;
            ExchangeTableModel *exchangeModel;
            FundTableModel *fundModel;
            GoldTableModel *goldModel;

            void updateModelsAndGUI();

            void cryptoCurrencyTransaction();
            void discountBondTransaction();
            void exchangeTransaction();
            void fundTransaction();
            void goldTransaction();
            void stockTransaction();
        };

    }

}

#endif // MAINWINDOW_H
