#include "GroupAbstractView.h"

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

QList<int> GroupAbstractView::getGroupids() const
{
    return groupids;
}

void GroupAbstractView::setGroupids(const QList<int> &value)
{
    groupids = value;
}

GroupAbstractView::GroupAbstractView(QWidget *parent)
    : QWidget(parent), viewState(NotSelectedState)
{
    container = new QStackedWidget;
}

GroupAbstractView::GroupAbstractView(GroupAbstractView *clone)
    : QWidget(clone)
{
    container = clone->getContainer();
    groupids = clone->getGroupids();
}
