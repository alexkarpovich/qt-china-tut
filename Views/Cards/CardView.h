#ifndef CARD_H
#define CARD_H

#include <QStackedWidget>
#include <QWidget>

#include <Views/AbstractMainView.h>
#include <Models/CardModel.h>
#include "CardAbstractView.h"


class CardView : public CardAbstractView
{
    Q_OBJECT

public:
    explicit CardView(AbstractMainView *parent);

signals:

public slots:
    //void onModelChanged();
};

#endif // CARD_H
