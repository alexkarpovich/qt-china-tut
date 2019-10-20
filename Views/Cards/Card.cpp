#include <QLabel>
#include <QVBoxLayout>
#include "Card.h"
#include <Views/Cards/CardAskView.h>
#include <Views/Cards/CardDetailView.h>

void Card::setViewState(Card::ViewState viewState)
{
    this->viewState = viewState;
    views->setCurrentIndex(viewState);
}

Card::Card(QWidget *parent)
    : QWidget(parent), viewState(AskState)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    views = new QStackedWidget;
    CardAskView *cardAskView = new CardAskView(this);
    CardDetailView *cardDetailView = new CardDetailView(this);
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
