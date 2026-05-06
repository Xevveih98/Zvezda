#include "mainwindow.h"

#include <QListWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QWidget>

#include "productspage.h"
#include "purchasespage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *central = new QWidget(this);
    auto *layout = new QHBoxLayout(central);

    menu = new QListWidget(this);
    menu->addItem("Products");
    menu->addItem("Purchases");
    menu->setFixedWidth(150);

    pages = new QStackedWidget(this);

    pages->addWidget(new ProductsPage(this));
    pages->addWidget(new PurchasesPage(this));

    layout->addWidget(menu);
    layout->addWidget(pages);

    setCentralWidget(central);

    connect(menu, &QListWidget::currentRowChanged,
            pages, &QStackedWidget::setCurrentIndex);

    menu->setCurrentRow(0);
}