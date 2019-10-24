#include <QDebug>
#include <QGridLayout>
#include <QSignalMapper>

#include <Dao/TrainingDao.h>

#include "GroupTrainingView.h"


GroupTrainingView::GroupTrainingView(GroupAbstractView *view)
    : GroupAbstractView(view)
{
    QGridLayout *rootLayout = new QGridLayout;
    QPushButton *tmp;

    qDebug() << getViewState() << *getViewState();

    for(int i = 0; i < 4; i++) {
        tmp = new QPushButton(QString::number(i), this);
        tmp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        btns.append(tmp);
        connect(btns[i], &QPushButton::clicked, [this, i]() { onTrainingOptionClicked(i); });
        rootLayout->addWidget(tmp, i/2, i%2);
    }
    setLayout(rootLayout);
}

void GroupTrainingView::onTrainingOptionClicked(int type)
{
    qDebug() << getViewState() << type << getGroupids();
    TrainingDao trainingDao;
    Training * tr = new Training;
    tr->setType(static_cast<Training::Type>(type));
    trainingDao.create(*getGroupids(), tr);
}
