#include <QDebug>
#include <QHBoxLayout>

#include "GroupView.h"

GroupView::GroupView(QWidget *parent) : QWidget(parent)
{
    buildLayout();
}

void GroupView::setGroups(QList<int> groupids)
{
    this->groupids = groupids;
    //editView->switchGroup(groupids);
    //setViewState(EditState);
}

void GroupView::buildLayout()
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    page = new GroupPage(this);
    rootLayout->addWidget(page);
    setLayout(rootLayout);
}
