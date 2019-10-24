#include <QDebug>

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
    setViewState(NotSelectedState);
}

void GroupAbstractView::setEditView()
{    
    setViewState(EditState);
}

void GroupAbstractView::setTrainingView()
{
    setViewState(TrainingState);
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

GroupAbstractView::ViewState *GroupAbstractView::getViewState() const
{
    return viewState;
}

void GroupAbstractView::setViewState(ViewState value)
{
    *viewState = value;
    container->setCurrentIndex(value);
}

PageAbstractView *GroupAbstractView::getPageView() const
{
    return pageView;
}

GroupAbstractView::GroupAbstractView(PageAbstractView *pageView)
    : QWidget(pageView), viewState(new ViewState), pageView(pageView), groupids(new QList<int>)
{
    *viewState = NotSelectedState;
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
    viewState = clone->getViewState();
    container = clone->getContainer();
    pageView = clone->getPageView();
    groupids = clone->getGroupids();
}
