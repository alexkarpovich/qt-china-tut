#include <QVBoxLayout>

#include <Views/TrainingView.h>

#include "CardAskView.h"
#include "CardView.h"


CardView::CardView(TrainingView *parent)
    : CardAbstractView(parent)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    if (getModel()->isNew()) {
        setAskView();
        getModel()->nextWord();

    } else {
        setCompleteView();
    }

    rootLayout->addWidget(container());
    setFixedSize(350, 200);
    setLayout(rootLayout);
}

