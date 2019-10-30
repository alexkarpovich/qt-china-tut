#include <QDebug>
#include <QGridLayout>
#include <QSignalMapper>

#include <Dao/TrainingDao.h>
#include <Views/TrainingView.h>
#include "GroupTrainingView.h"



GroupTrainingView::GroupTrainingView(GroupAbstractView *view)
    : GroupAbstractView(view)
{
    QGridLayout *rootLayout = new QGridLayout;
    QPushButton *tmp;
    backBtn = new QPushButton("Вернуться");

    rootLayout->addWidget(backBtn, 0, 0, 1, 2);
    connect(backBtn, SIGNAL(clicked()), this, SLOT(onBackBtnClicked()));

    for(int i = 0; i < 4; i++) {
        tmp = new QPushButton(QString::number(i), this);
        tmp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        btns.append(tmp);
        connect(btns[i], &QPushButton::clicked, [this, i]() {
            onTrainingOptionClicked(static_cast<Training::Type>(i));
        });
        rootLayout->addWidget(tmp, i/2 + 1, i%2);
    }
    setLayout(rootLayout);
}

void GroupTrainingView::onBackBtnClicked()
{
    setEditView();
}

void GroupTrainingView::onTrainingOptionClicked(Training::Type type)
{
    TrainingView *trainingView = new TrainingView(*getGroupids(), type, getPageView());
    getPageView()->setTrainingView(trainingView);
}
