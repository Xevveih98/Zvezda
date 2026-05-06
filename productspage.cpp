#include "productspage.h"

#include <QVBoxLayout>
#include <QTableView>
#include <QtSql/QSqlTableModel>

ProductsPage::ProductsPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    table = new QTableView(this);

    model = new QSqlTableModel(this);
    model->setTable("Товары");
    model->select();

    table->setModel(model);

    layout->addWidget(table);
}