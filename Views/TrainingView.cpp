#include "TrainingView.h"

#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

#include "Cards/CardView.h"

TrainingView::TrainingView(AbstractMainView *view)
    : AbstractMainView(view)
{
    QVBoxLayout * rootLayout = new QVBoxLayout;

    cardView = new CardView(this);
    rootLayout->addWidget(cardView, 1, Qt::AlignHCenter);

    setLayout(rootLayout);
}

void TrainingView::activate()
{
    cardView->activate();
}
