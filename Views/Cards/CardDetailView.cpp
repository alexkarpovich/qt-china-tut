#include <QGridLayout>

#include "CardDetailView.h"


CardDetailView::CardDetailView(CardAbstractView *view)
    : CardAbstractView(view)
{
    QGridLayout *rootLayout = new QGridLayout;
    wordLbl = new QLabel;
    QFont lblFont;
    lblFont.setBold(true);
    lblFont.setPointSize(16);
    wordLbl->setFont(lblFont);
    transcriptionLbl = new QLabel;
    translationLbl = new QLabel;
    completeBtn = new QPushButton("дальше");
    repeatBtn = new QPushButton("повторить");

    rootLayout->addWidget(wordLbl, 0, 0, 2, 1);
    rootLayout->addWidget(transcriptionLbl, 0, 1);
    rootLayout->addWidget(translationLbl, 1,1);
    rootLayout->addWidget(repeatBtn, 2, 0);
    rootLayout->addWidget(completeBtn, 2, 1);

    setLayout(rootLayout);

    onModelChanged();
    connect(getModel(), SIGNAL(dataChanged()), this, SLOT(onModelChanged()));
    connect(completeBtn, SIGNAL(clicked()), this, SLOT(onCompleteBtnClicked()));
    connect(repeatBtn, SIGNAL(clicked()), this, SLOT(onRepeatBtnClicked()));
}

void CardDetailView::onModelChanged()
{
    if (!getModel()->isComplete()) {
        wordLbl->setText(getModel()->foreigh()->getText());
        transcriptionLbl->setText(getModel()->foreigh()->getTranscription());
        translationLbl->setText(getModel()->native()->getText());
    }
}

void CardDetailView::onRepeatBtnClicked()
{
    getModel()->nextWord();
    setAskView();
}

void CardDetailView::onCompleteBtnClicked()
{
    getModel()->completeWord();

    if (!getModel()->isComplete()) {
        setAskView();
    } else {
        setCompleteView();
    }
}
