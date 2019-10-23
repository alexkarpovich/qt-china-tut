#include "GroupAbstractView.h"
#include "GroupNotSelectedView.h"
#include "GroupEditView.h"
#include "GroupTrainingView.h"

QStackedWidget *GroupAbstractView::getContainer() const
{
    return container;
}

void GroupAbstractView::setContainer(QStackedWidget *value)
{
    container = value;
}

void GroupAbstractView::setNotSelectedView()
{
    container->setCurrentIndex(NotSelectedState);
}

void GroupAbstractView::setEditView()
{
    editView->switchGroup(groupids);
    container->setCurrentIndex(EditState);
}

void GroupAbstractView::setTrainingView()
{
    container->setCurrentIndex(TrainingState);
}

QList<int> GroupAbstractView::getGroupids() const
{
    return groupids;
}

void GroupAbstractView::setGroupids(const QList<int> &value)
{
    groupids = value;

    if (groupids.size() && viewState == NotSelectedState) {
        setEditView();
    }
}

GroupAbstractView::GroupAbstractView(QWidget *parent)
    : QWidget(parent), viewState(NotSelectedState)
{
    container = new QStackedWidget;
    notSelectedView = new GroupNotSelectedView(this);
    editView = new GroupEditView(this);
    trainingView = new GroupTrainingView(this);
    container->addWidget(notSelectedView);
    container->addWidget(editView);
    container->addWidget(trainingView);
}

GroupAbstractView::GroupAbstractView(GroupAbstractView *clone)
    : QWidget(clone)
{
    container = clone->getContainer();
    groupids = clone->getGroupids();
}
