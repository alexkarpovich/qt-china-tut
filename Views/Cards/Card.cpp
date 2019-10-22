#include <QLabel>
#include <QVBoxLayout>
#include "Card.h"
#include <Views/Cards/CardAskView.h>
#include <Views/Cards/CardDetailView.h>

CardModel *Card::getModel() const
{
    return model;
}

void Card::setModel(CardModel *value)
{
    model = value;
}

void Card::onModelChanged()
{

}

void Card::setViewState(Card::ViewState viewState)
{
    this->viewState = viewState;
    views->setCurrentIndex(viewState);
}

Card::Card(QWidget *parent)
    : QWidget(parent), viewState(AskState)
{
    model = new CardModel();
    connect(model, SIGNAL(dataChanged()), this, SLOT(onModelChanged()));
    QVBoxLayout *rootLayout = new QVBoxLayout;
    views = new QStackedWidget;
    CardAskView *cardAskView = new CardAskView(model, this);
    CardDetailView *cardDetailView = new CardDetailView(model, this);
    views->addWidget(cardAskView);
    views->addWidget(cardDetailView);
    rootLayout->addWidget(views);
    setFixedSize(350, 200);
    setLayout(rootLayout);
}

void Card::setDetailView()
{
    setViewState(DetailState);
}
