#include "CardAbstractView.h"
#include "CardAskView.h"
#include "CardDetailView.h"
#include "CardCompleteView.h"

CardAbstractView::CardAbstractView(AbstractPageView *parent)
    : AbstractPageView(parent)
{
    model = new CardModel;
    setContainer(new QStackedWidget(this));
    askView = new CardAskView(this);
    detailView = new CardDetailView(this);
    completeView = new CardCompleteView(this);
}

CardAbstractView::CardAbstractView(CardAbstractView *clone)
    : AbstractPageView(clone)
{
    model = clone->getModel();
    askView = clone->getAskView();
    detailView = clone->getDetailView();
    completeView = clone->getCompleteView();
}

CardModel *CardAbstractView::getModel() const
{
    return model;
}

void CardAbstractView::setModel(CardModel *value)
{
    model = value;
}

void CardAbstractView::activate()
{
    model->initialize();
}

void CardAbstractView::setAskView()
{
    setCurrentWidget(askView);
}

void CardAbstractView::setDetailView()
{
    setCurrentWidget(detailView);
}

void CardAbstractView::setCompleteView()
{
    setCurrentWidget(completeView);
}

CardAskView *CardAbstractView::getAskView() const
{
    return askView;
}

CardDetailView *CardAbstractView::getDetailView() const
{
    return detailView;
}

CardCompleteView *CardAbstractView::getCompleteView() const
{
    return completeView;
}
