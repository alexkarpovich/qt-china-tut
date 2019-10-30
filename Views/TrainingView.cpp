#include "TrainingView.h"
#include <QDebug>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "Cards/CardView.h"

TrainingView::TrainingView(QList<int> groupids, Training::Type type, AbstractMainView *view)
    : AbstractMainView(view)
{
    QVBoxLayout * rootLayout = new QVBoxLayout;
    QPushButton *backBtn = new QPushButton("Вернуться");
    trainingModel = new TrainingModel(groupids, type);
    cardView = new CardView(this);
    rootLayout->addWidget(backBtn, 0, Qt::AlignTop);
    rootLayout->addWidget(cardView, 1, Qt::AlignHCenter);

    setLayout(rootLayout);

    connect(backBtn, SIGNAL(clicked()), this, SLOT(onBackBtnClicked()));
}

TrainingModel *TrainingView::getTrainingModel() const
{
    return trainingModel;
}

void TrainingView::onBackBtnClicked()
{
    setManagementView();
}
