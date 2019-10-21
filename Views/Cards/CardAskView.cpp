#include "Card.h"
#include "CardAskView.h"

#include <QVBoxLayout>

CardAskView::CardAskView(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    textLbl = new QLabel("Text");
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
    Card * cardView = qobject_cast<Card *>(parent()->parent());
    cardView->setDetailView();
}