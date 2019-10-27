#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

#include "GroupNotSelectedView.h"


GroupNotSelectedView::GroupNotSelectedView(GroupAbstractView *view)
    : GroupAbstractView(view)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    QLabel *msgLabel = new QLabel("Выберите группу для просмотра.");
    rootLayout->addWidget(msgLabel);
    setLayout(rootLayout);
}
