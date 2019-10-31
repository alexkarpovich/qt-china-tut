#include <QDebug>

#include <Views/ManagementView.h>
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

GroupModel *GroupAbstractView::getGroupModel() const
{
    return groupModel;
}

void GroupAbstractView::setGroupModel(GroupModel *value)
{
    groupModel = value;
}

GroupAbstractView::GroupAbstractView(ManagementView *parent)
    : AbstractPageView(parent), groupids(new QList<int>), pageView(parent)
{
    groupModel = parent->getGroupModel();
    setContainer(new QStackedWidget(this));
}

GroupAbstractView::GroupAbstractView(GroupAbstractView *clone)
    : AbstractPageView(clone)
{
    //setVisible(false);
    pageView = clone->getPageView();
    groupids = clone->getGroupids();
    groupModel = clone->getGroupModel();
}
