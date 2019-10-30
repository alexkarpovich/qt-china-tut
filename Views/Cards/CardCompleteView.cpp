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

    connect(getModel(), SIGNAL(dataChanged()), this, SLOT(onModelChanged()));
    connect(resetBtn, SIGNAL(clicked()), this, SLOT(onResetBtnClicked()));
    connect(continueBtn, SIGNAL(clicked()), this, SLOT(onContinueBtnClicked()));

    onModelChanged();
}


void CardCompleteView::onModelChanged()
{
    if (getModel()->isComplete()) {
        continueBtn->setVisible(false);
    } else {
        continueBtn->setVisible(true);
    }
}

void CardCompleteView::onResetBtnClicked()
{
    setAskView();
    getModel()->reset();
}

void CardCompleteView::onContinueBtnClicked()
{
    setAskView();
    getModel()->nextWord();
}
