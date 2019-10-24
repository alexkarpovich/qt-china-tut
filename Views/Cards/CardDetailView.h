#ifndef CARDDETAILVIEW_H
#define CARDDETAILVIEW_H

#include <QWidget>

#include <Models/CardModel.h>
#include "CardAbstractView.h"

class CardDetailView : public CardAbstractView
{
    Q_OBJECT

public:
    explicit CardDetailView(CardAbstractView *view);

signals:

public slots:
};

#endif // CARDDETAILVIEW_H
