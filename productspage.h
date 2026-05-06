#ifndef PRODUCTSPAGE_H
#define PRODUCTSPAGE_H

#include <QWidget>

class QTableView;
class QSqlTableModel;

class ProductsPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProductsPage(QWidget *parent = nullptr);

private:
    QTableView *table;
    QSqlTableModel *model;
};

#endif // PRODUCTSPAGE_H