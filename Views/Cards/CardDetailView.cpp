#include <QGridLayout>

#include "CardDetailView.h"


CardDetailView::CardDetailView(CardAbstractView *view)
    : CardAbstractView(view)
{
    QGridLayout *rootLayout = new QGridLayout;
    wordLbl = new QLabel(getModel()->getForeignWord()->getText());
    transcriptionLbl = new QLabel(getModel()->getForeignWord()->getTranscription());
    translationLbl = new QLabel(getModel()->getNativeWord()->getText());
    completeBtn = new QPushButton("дальше");
    repeatBtn = new QPushButton("повторить");
    QFont lblFont;
    lblFont.setBold(true);
    lblFont.setPointSize(20);

    rootLayout->addWidget(wordLbl, 0, 0, 2, 1);
    rootLayout->addWidget(transcriptionLbl, 0, 1);
    rootLayout->addWidget(translationLbl, 1,1);
    rootLayout->addWidget(repeatBtn, 2, 0);
    rootLayout->addWidget(completeBtn, 2, 1);

    setLayout(rootLayout);

    connect(getModel(), SIGNAL(dataChanged()), this, SLOT(onModelChanged()));
    connect(completeBtn, SIGNAL(clicked()), this, SLOT(onCompleteBtnClicked()));
    connect(repeatBtn, SIGNAL(clicked()), this, SLOT(onRepeatBtnClicked()));
}

void CardDetailView::onModelChanged()
{
    wordLbl->setText(getModel()->getForeignWord()->getText());
    transcriptionLbl->setText(getModel()->getForeignWord()->getTranscription());
    translationLbl->setText(getModel()->getNativeWord()->getText());
}

void CardDetailView::onRepeatBtnClicked()
{
    getModel()->next();
    setAskView();
}

void CardDetailView::onCompleteBtnClicked()
{
    getModel()->complete();
    setAskView();
}
