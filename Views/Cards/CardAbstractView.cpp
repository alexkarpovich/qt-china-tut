#include "CardAbstractView.h"
#include "CardAskView.h"
#include "CardDetailView.h"
#include "CardCompleteView.h"

CardAbstractView::CardAbstractView(AbstractPageView *parent)
    : AbstractPageView(parent)
{
    setContainer(new QStackedWidget(this));
    model = new CardModel;
    askView = new CardAskView(this);
    detailView = new CardDetailView(this);
    completeView = new CardCompleteView(this);
    addPage(typeid(CardAskView), askView);
    addPage(typeid(CardDetailView), detailView);
    addPage(typeid(CardCompleteView), completeView);
}

CardAbstractView::CardAbstractView(CardAbstractView *clone)
    : AbstractPageView(clone)
{
    setVisible(false);
    model = clone->getModel();
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
    setCurrentWidget(typeid(CardAskView));
}

void CardAbstractView::setDetailView()
{
    setCurrentWidget(typeid(CardDetailView));
}

void CardAbstractView::setCompleteView()
{
    setCurrentWidget(typeid(CardCompleteView));
}
