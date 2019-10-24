#ifndef CARDCOMPLETEVIEW_H
#define CARDCOMPLETEVIEW_H

#include <QPushButton>

#include "CardAbstractView.h"


class CardCompleteView : public CardAbstractView
{
    Q_OBJECT

    QPushButton *resetBtn;
public:
    CardCompleteView(CardAbstractView *view);

public slots:
    void onModelChanged();
    void onResetBtnClicked();
};

#endif // CARDCOMPLETEVIEW_H
