#include "CardAbstractView.h"
#include "CardAskView.h"
#include "CardDetailView.h"
#include "CardCompleteView.h"

CardAbstractView::CardAbstractView(QWidget *parent)
    : QWidget(parent), viewState(new ViewState)
{
    *viewState = AskState;
    model = new CardModel;
    container = new QStackedWidget;
    askView = new CardAskView(this);
    detailView = new CardDetailView(this);
    completeView = new CardCompleteView(this);
    container->addWidget(askView);
    container->addWidget(detailView);
    container->addWidget(completeView);
}

CardAbstractView::CardAbstractView(CardAbstractView *clone)
    : QWidget(clone)
{
    viewState = clone->getViewState();
    model = clone->getModel();
    container = clone->getContainer();
}

CardAbstractView::ViewState *CardAbstractView::getViewState() const
{
    return viewState;
}

void CardAbstractView::setViewState(ViewState value)
{
    *viewState = value;
    container->setCurrentIndex(value);
}

CardModel *CardAbstractView::getModel() const
{
    return model;
}

void CardAbstractView::setModel(CardModel *value)
{
    model = value;
}

QStackedWidget *CardAbstractView::getContainer() const
{
    return container;
}

void CardAbstractView::activate()
{
    model->initialize();
}

void CardAbstractView::setAskView()
{
    setViewState(AskState);
}

void CardAbstractView::setDetailView()
{
    setViewState(DetailState);
}

void CardAbstractView::setCompleteView()
{
    setViewState(CompleteState);
}
