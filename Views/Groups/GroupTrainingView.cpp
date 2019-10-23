#include "GroupTrainingView.h"

#include <QGridLayout>

GroupTrainingView::GroupTrainingView(GroupAbstractView *view)
    : GroupAbstractView(view)
{
    QGridLayout *rootLayout = new QGridLayout;
    QPushButton *tmp;
    for(int i = 0; i < 4; i++) {
        tmp = new QPushButton(QString::number(i));
        tmp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        btns.append(tmp);
        rootLayout->addWidget(tmp, i/2, i%2);
    }
    setLayout(rootLayout);
}
