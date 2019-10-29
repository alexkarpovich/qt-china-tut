#include <QVBoxLayout>

#include <Views/TrainingView.h>

#include "CardAskView.h"
#include "CardView.h"


CardView::CardView(TrainingView *parent)
    : CardAbstractView(parent)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    setAskView();
    rootLayout->addWidget(container());
    setFixedSize(350, 200);
    setLayout(rootLayout);
}

