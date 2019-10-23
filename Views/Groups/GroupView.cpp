#include <QDebug>
#include <QHBoxLayout>

#include "GroupView.h"

GroupView::GroupView(QWidget *parent)
    : GroupAbstractView(parent)
{
    buildLayout();
}

void GroupView::buildLayout()
{
    QHBoxLayout *rootLayout = new QHBoxLayout;    
    rootLayout->addWidget(getContainer());
    setLayout(rootLayout);
}
