#ifndef CARDASKVIEW_H
#define CARDASKVIEW_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include <Models/CardModel.h>
#include "CardAbstractView.h"

class CardAskView : public CardAbstractView
{
    Q_OBJECT

    QLabel *textLbl;
    QPushButton *showBtn;
public:
    explicit CardAskView(CardAbstractView *view);

signals:

public slots:
    void onModelChanged();
    void onShowBtnClicked();
};

#endif // CARDASKVIEW_H
