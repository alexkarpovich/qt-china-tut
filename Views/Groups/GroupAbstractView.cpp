#include <QDebug>

#include "GroupAbstractView.h"
#include "GroupNotSelectedView.h"
#include "GroupEditView.h"
#include "GroupTrainingView.h"

void GroupAbstractView::setNotSelectedView()
{
    setCurrentWidget(notSelectedView);
}

void GroupAbstractView::setEditView()
{    
    setCurrentWidget(editView);
}

void GroupAbstractView::setTrainingView()
{
    setCurrentWidget(trainingView);
}

QList<int> *GroupAbstractView::getGroupids() const
{
    return groupids;
}

void GroupAbstractView::setGroupids(QList<int> value)
{
    *groupids = value;
    emit dataChanged();
}

AbstractMainView *GroupAbstractView::getPageView() const
{
    return pageView;
}

bool GroupAbstractView::isNotSelectedView()
{
    return container()->currentWidget() == notSelectedView;
}

GroupNotSelectedView *GroupAbstractView::getNotSelectedView() const
{
    return notSelectedView;
}

GroupEditView *GroupAbstractView::getEditView() const
{
    return editView;
}

GroupTrainingView *GroupAbstractView::getTrainingView() const
{
    return trainingView;
}

void GroupAbstractView::activate()
{

}

GroupAbstractView::GroupAbstractView(AbstractMainView *pageView)
    : AbstractPageView(pageView), groupids(new QList<int>), pageView(pageView)
{
    setContainer(new QStackedWidget(this));
    notSelectedView = new GroupNotSelectedView(this);
    editView = new GroupEditView(this);
    trainingView = new GroupTrainingView(this);
    notSelectedView->setVisible(false);
    editView->setVisible(false);
    trainingView->setVisible(false);
}

GroupAbstractView::GroupAbstractView(GroupAbstractView *clone)
    : AbstractPageView(clone)
{
    pageView = clone->getPageView();
    groupids = clone->getGroupids();
    notSelectedView = clone->getNotSelectedView();
    editView = clone->getEditView();
    trainingView = clone->getTrainingView();
}
