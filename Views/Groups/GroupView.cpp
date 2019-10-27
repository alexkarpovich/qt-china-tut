#include <QDebug>
#include <QHBoxLayout>

#include "GroupView.h"

GroupView::GroupView(AbstractMainView *pageView)
    : GroupAbstractView(pageView)
{
    buildLayout();
}

void GroupView::buildLayout()
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    setNotSelectedView();
    rootLayout->addWidget(container());
    setLayout(rootLayout);
}
