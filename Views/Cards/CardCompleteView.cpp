#include <QVBoxLayout>

#include "CardCompleteView.h"

CardCompleteView::CardCompleteView(CardAbstractView *view)
    : CardAbstractView(view)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    resetBtn = new QPushButton("Начать заново");
    rootLayout->addWidget(resetBtn);
    setLayout(rootLayout);

    connect(getModel(), SIGNAL(dataChanged()), this, SLOT(onModelChanged()));
    connect(resetBtn, SIGNAL(clicked()), this, SLOT(onResetBtnClicked()));
}

void CardCompleteView::onModelChanged()
{
    if (getModel()->isComplete()) {
        setCompleteView();
    }
}

void CardCompleteView::onResetBtnClicked()
{
    getModel()->reset();
}
