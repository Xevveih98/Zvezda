#include "balancepage.h"

#include <QVBoxLayout>
#include <QLabel>

BalancePage::BalancePage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Баланс"));
}