#include "TrainingView.h"
#include <QDebug>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

#include "Cards/CardView.h"

TrainingModel *TrainingView::getTrainingModel() const
{
    return trainingModel;
}

TrainingView::TrainingView(QList<int> groupids, Training::Type type, AbstractMainView *view)
    : AbstractMainView(view)
{
    QVBoxLayout * rootLayout = new QVBoxLayout;
    trainingModel = new TrainingModel(groupids, type);
    cardView = new CardView(this);
    rootLayout->addWidget(cardView, 1, Qt::AlignHCenter);

    setLayout(rootLayout);
}

void TrainingView::activate()
{
    qDebug() << "Training activated";
    cardView->activate();
}
