#include <QVBoxLayout>

#include "CardView.h"

CardView::CardView(AbstractMainView *parent)
    : CardAbstractView(parent)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    rootLayout->addWidget(container());
    setFixedSize(350, 200);
    setLayout(rootLayout);
}

