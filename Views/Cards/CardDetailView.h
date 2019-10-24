#ifndef CARDDETAILVIEW_H
#define CARDDETAILVIEW_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include <Models/CardModel.h>
#include "CardAbstractView.h"

class CardDetailView : public CardAbstractView
{
    Q_OBJECT

public:
    explicit CardDetailView(CardAbstractView *view);

private:
    QLabel *wordLbl;
    QLabel *transcriptionLbl;
    QLabel *translationLbl;
    QPushButton *completeBtn;
    QPushButton *repeatBtn;
signals:

public slots:
    void onModelChanged();
    void onCompleteBtnClicked();
    void onRepeatBtnClicked();
};

#endif // CARDDETAILVIEW_H
