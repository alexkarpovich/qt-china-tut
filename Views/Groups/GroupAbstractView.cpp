#include <QDebug>

#include "GroupAbstractView.h"
#include "GroupNotSelectedView.h"
#include "GroupEditView.h"
#include "GroupTrainingView.h"

void GroupAbstractView::setNotSelectedView()
{
    setCurrentWidget(typeid(GroupNotSelectedView));
}

void GroupAbstractView::setEditView()
{    
    setCurrentWidget(typeid(GroupEditView));
}

void GroupAbstractView::setTrainingView()
{
    setCurrentWidget(typeid(GroupTrainingView));
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
    return container()->currentWidget() == page(typeid(GroupNotSelectedView));
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
    addPage(typeid(GroupNotSelectedView), notSelectedView);
    addPage(typeid(GroupEditView), editView);
    addPage(typeid(GroupTrainingView), trainingView);
}

GroupAbstractView::GroupAbstractView(GroupAbstractView *clone)
    : AbstractPageView(clone)
{
    setVisible(false);
    pageView = clone->getPageView();
    groupids = clone->getGroupids();
}
