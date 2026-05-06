#include "mainwindow.h"

#include <QListWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QWidget>

#include "productspage.h"
#include "purchasespage.h"
#include "balancepage.h"
#include "recipespage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *central = new QWidget(this);
    auto *layout = new QHBoxLayout(central);

    menu = new QListWidget(this);
    menu->addItem("Товары");
    menu->addItem("Покупки");
    menu->addItem("Баланс");
    menu->addItem("Рецепты");
    menu->setFixedWidth(150);

    pages = new QStackedWidget(this);

    pages->addWidget(new ProductsPage(this));
    pages->addWidget(new PurchasesPage(this));
    pages->addWidget(new BalancePage(this));
    pages->addWidget(new RecipesPage(this));

    layout->addWidget(menu);
    layout->addWidget(pages);

    setCentralWidget(central);

    connect(menu, &QListWidget::currentRowChanged,
            pages, &QStackedWidget::setCurrentIndex);

    menu->setCurrentRow(0);
}