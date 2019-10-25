#ifndef CARDCOMPLETEVIEW_H
#define CARDCOMPLETEVIEW_H

#include <QPushButton>

#include "CardAbstractView.h"


class CardCompleteView : public CardAbstractView
{
    Q_OBJECT

    QPushButton *resetBtn;
    QPushButton *continueBtn;
public:
    CardCompleteView(CardAbstractView *view);

public slots:
    void onResetBtnClicked();
    void onContinueBtnClicked();
};

#endif // CARDCOMPLETEVIEW_H
