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
    //setVisible(false);
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

void CardAbstractView::setAskView(CardAskView *view)
{
    CardAskView *existingView = static_cast<CardAskView *>(page(typeid (CardAskView)));

    if (!existingView && !view) {
        view = new CardAskView(this);
    }

    if (!existingView) {
        addPage(typeid(CardAskView), view);
    }

    setCurrentWidget(typeid(CardAskView));
}

void CardAbstractView::setDetailView(CardDetailView *view)
{
    CardDetailView *existingView = static_cast<CardDetailView *>(page(typeid (CardDetailView)));

    if (!existingView && !view) {
        view = new CardDetailView(this);
    }

    if (!existingView) {
        addPage(typeid(CardDetailView), view);
    }

    setCurrentWidget(typeid(CardDetailView));
}

void CardAbstractView::setCompleteView(CardCompleteView *view)
{
    CardCompleteView *existingView = static_cast<CardCompleteView *>(page(typeid (CardCompleteView)));

    if (!existingView && !view) {
        view = new CardCompleteView(this);
    }

    if (!existingView) {
        addPage(typeid(CardCompleteView), view);
    }

    setCurrentWidget(typeid(CardCompleteView));
}
