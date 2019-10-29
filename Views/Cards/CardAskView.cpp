#include <QVBoxLayout>

#include "CardView.h"
#include "CardAskView.h"

CardAskView::CardAskView(CardAbstractView *view)
    : CardAbstractView(view)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    textLbl = new QLabel("hello");
    QFont lblFont;
    lblFont.setBold(true);
    lblFont.setPointSize(20);
    textLbl->setFont(lblFont);
    showBtn = new QPushButton("Показать");
    rootLayout->addWidget(textLbl, 0, Qt::AlignCenter);
    rootLayout->addWidget(showBtn, 0, Qt::AlignBottom);
    setLayout(rootLayout);

    connect(getModel(), SIGNAL(dataChanged()), this, SLOT(onModelChanged()));
    connect(showBtn, SIGNAL(clicked()), this, SLOT(onShowBtnClicked()));
}

void CardAskView::onModelChanged()
{
    if (!getModel()->isComplete()) {
        QString text = getModel()->native()->getText();
        textLbl->setText(text);
    }
}

void CardAskView::onShowBtnClicked()
{
    setDetailView();
}
