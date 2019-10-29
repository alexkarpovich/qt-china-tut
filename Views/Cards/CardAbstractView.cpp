#include <Views/TrainingView.h>
#include "CardAbstractView.h"
#include "CardAskView.h"
#include "CardDetailView.h"
#include "CardCompleteView.h"

CardAbstractView::CardAbstractView(TrainingView *parent)
    : AbstractPageView(parent)
{
    setContainer(new QStackedWidget(this));
    model = parent->getTrainingModel();
}

CardAbstractView::CardAbstractView(CardAbstractView *clone)
    : AbstractPageView(clone)
{
    setVisible(false);
    model = clone->getModel();
}

TrainingModel *CardAbstractView::getModel() const
{
    return model;
}

void CardAbstractView::setModel(TrainingModel *value)
{
    model = value;
}

void CardAbstractView::activate()
{
    model->nextWord();
}

void CardAbstractView::setAskView(CardAskView *view)
{
    if (view) {
        askView = view;
    } else {
        askView = askView ? askView : new CardAskView(this);
    }

    addPage(typeid(CardAskView), askView);
    setCurrentWidget(typeid(CardAskView));
}

void CardAbstractView::setDetailView(CardDetailView *view)
{
    if (view) {
        detailView = view;
    } else {
        detailView = detailView ? detailView : new CardDetailView(this);
    }

    addPage(typeid(CardDetailView), detailView);
    setCurrentWidget(typeid(CardDetailView));
}

void CardAbstractView::setCompleteView(CardCompleteView *view)
{
    if (view) {
        completeView = view;
    } else {
        completeView = completeView ? completeView : new CardCompleteView(this);
    }

    addPage(typeid(CardCompleteView), completeView);
    setCurrentWidget(typeid(CardCompleteView));
}
