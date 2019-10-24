#include <QDebug>
#include <QHBoxLayout>

#include "GroupView.h"

GroupView::GroupView(PageAbstractView *pageView)
    : GroupAbstractView(pageView)
{
    buildLayout();
}

void GroupView::buildLayout()
{
    QHBoxLayout *rootLayout = new QHBoxLayout;    
    rootLayout->addWidget(getContainer());
    setLayout(rootLayout);
}
