#include <QVBoxLayout>

#include "CardCompleteView.h"

CardCompleteView::CardCompleteView(CardAbstractView *view)
    : CardAbstractView(view)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    resetBtn = new QPushButton("ЗАНОВО");
    continueBtn = new QPushButton("ПРОДОЛЖИТЬ");
    rootLayout->addWidget(resetBtn);
    rootLayout->addWidget(continueBtn);
    setLayout(rootLayout);

    connect(resetBtn, SIGNAL(clicked()), this, SLOT(onResetBtnClicked()));
    connect(continueBtn, SIGNAL(clicked()), this, SLOT(onContinueBtnClicked()));
}

void CardCompleteView::onResetBtnClicked()
{
    getModel()->reset();
    setAskView();
}

void CardCompleteView::onContinueBtnClicked()
{
    getModel()->next();
    setAskView();
}
