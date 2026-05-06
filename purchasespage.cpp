#include "purchasespage.h"

#include <QVBoxLayout>
#include <QLabel>

PurchasesPage::PurchasesPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Покупки"));
}