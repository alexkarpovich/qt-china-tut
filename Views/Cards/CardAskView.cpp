#include <QVBoxLayout>

#include "CardView.h"
#include "CardAskView.h"

CardAskView::CardAskView(CardAbstractView *view)
    : CardAbstractView(view)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    textLbl = new QLabel("TEXT" /*view->getNativeWord()->getText()*/);
    QFont lblFont;
    lblFont.setBold(true);
    lblFont.setPointSize(20);
    textLbl->setFont(lblFont);
    showBtn = new QPushButton("Показать");
    rootLayout->addWidget(textLbl, 0, Qt::AlignCenter);
    rootLayout->addWidget(showBtn, 0, Qt::AlignBottom);
    setLayout(rootLayout);

    connect(showBtn, SIGNAL(clicked()), this, SLOT(onShowBtnClicked()));
}

void CardAskView::onShowBtnClicked()
{
    setDetailView();
}
