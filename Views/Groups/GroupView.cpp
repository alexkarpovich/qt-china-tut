#include <QDebug>
#include <QHBoxLayout>

#include "GroupView.h"

GroupView::GroupView(QWidget *parent)
    : GroupAbstractView(parent)
{
    buildLayout();
}

void GroupView::buildLayout()
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    notSelectedView = new GroupNotSelectedView(this);
    trainingView = new GroupTrainingView(this);
    editView = new GroupEditView(this);
    getContainer()->addWidget(notSelectedView);
    getContainer()->addWidget(editView);
    getContainer()->addWidget(trainingView);
    setNotSelectedView();
    rootLayout->addWidget(getContainer());
    setLayout(rootLayout);
}
