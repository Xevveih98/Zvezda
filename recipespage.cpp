#include "recipespage.h"

#include <QVBoxLayout>
#include <QLabel>

RecipesPage::RecipesPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Рецепты"));
}