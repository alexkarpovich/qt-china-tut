#ifndef CARD_H
#define CARD_H

#include <QStackedWidget>
#include <QWidget>

#include <Models/TrainingModel.h>

#include <Views/AbstractMainView.h>
#include "CardAbstractView.h"


class CardView : public CardAbstractView
{
    Q_OBJECT
    TrainingModel *trainingModel;
public:
    explicit CardView(AbstractMainView *parent);

signals:

public slots:
    //void onModelChanged();
};

#endif // CARD_H
