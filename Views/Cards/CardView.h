#ifndef CARD_H
#define CARD_H

#include <QStackedWidget>
#include <QWidget>

#include <Models/CardModel.h>
#include "CardAbstractView.h"


class CardView : public CardAbstractView
{
    Q_OBJECT

public:
    explicit CardView(QWidget *parent = nullptr);

signals:

public slots:
    //void onModelChanged();
};

#endif // CARD_H
