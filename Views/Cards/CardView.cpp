#include <QVBoxLayout>

#include "CardView.h"

CardView::CardView(QWidget *parent)
    : CardAbstractView(parent)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    rootLayout->addWidget(getContainer());
    setFixedSize(350, 200);
    setLayout(rootLayout);
}

