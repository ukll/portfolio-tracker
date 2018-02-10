#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "investpor/core/portfolioxml.h"
#include "investpor/gui/cryptocurrencytablemodel.h"
#include "investpor/gui/discountbondtablemodel.h"
#include "investpor/gui/exchangetablemodel.h"
#include "investpor/gui/fundtablemodel.h"
#include "investpor/gui/goldtablemodel.h"
#include "investpor/gui/stocktablemodel.h"

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

            PortfolioXML *portfolio = nullptr;
            CryptocurrencyTableModel *cryptoCurrencyModel;
            DiscountBondTableModel *discountBondModel;
            ExchangeTableModel *exchangeModel;
            FundTableModel *fundModel;
            GoldTableModel *goldModel;
            StockTableModel *stockModel;

            void readApplicationSettings();
            void writeApplicationSettings();

            void newPortfolio();
            void openPortfolio();
            void connectModels();
            void updateModelsAndGUI();

            void cryptoCurrencyTransaction();
            void discountBondTransaction();
            void exchangeTransaction();
            void fundTransaction();
            void goldTransaction();
            void stockTransaction();

            virtual void closeEvent(QCloseEvent *event) override;
        };

    }

}

#endif // MAINWINDOW_H
