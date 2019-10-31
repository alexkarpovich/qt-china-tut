#include <QDebug>
#include <QHBoxLayout>

#include "GroupEditView.h"
#include "GroupNotSelectedView.h"
#include "GroupView.h"

GroupView::GroupView(ManagementView *view)
    : GroupAbstractView(view)
{
    buildLayout();
}

void GroupView::buildLayout()
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    GroupNotSelectedView *notSelectedView = new GroupNotSelectedView(this);
    addPage(typeid (GroupNotSelectedView), notSelectedView);
    setNotSelectedView();
    connect(this, SIGNAL(dataChanged()), this, SLOT(onDataChanged()));
    rootLayout->addWidget(container());
    setLayout(rootLayout);
}

void GroupView::onDataChanged()
{
    if (isNotSelectedView() && getGroupids()->size()) {
        GroupEditView *editView = new GroupEditView(this);
        connect(this, SIGNAL(dataChanged()), editView, SLOT(onDataChanged()));
        addPage(typeid(GroupEditView), editView);
        setEditView();
    }
}
