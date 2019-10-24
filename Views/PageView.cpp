#include <QHBoxLayout>

#include "PageView.h"


PageView::PageView(QWidget *parent)
    : PageAbstractView(parent)
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    rootLayout->addWidget(getContainer());
    setLayout(rootLayout);
}
