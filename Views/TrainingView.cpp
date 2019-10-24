#include "TrainingView.h"

#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

#include "Cards/CardView.h"

TrainingView::TrainingView(PageAbstractView *view)
    : PageAbstractView(view)
{
    QVBoxLayout * rootLayout = new QVBoxLayout;

    CardView *cardView = new CardView(this);
    rootLayout->addWidget(cardView, 1, Qt::AlignHCenter);

    setLayout(rootLayout);
}
