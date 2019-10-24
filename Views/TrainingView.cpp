#include "TrainingView.h"

#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

#include <Views/Cards/Card.h>

TrainingView::TrainingView(PageAbstractView *view)
    : PageAbstractView(view)
{
    QVBoxLayout * rootLayout = new QVBoxLayout;

    //Card *card = new Card;
    //rootLayout->addWidget(card, 1, Qt::AlignHCenter);

    setLayout(rootLayout);
}
