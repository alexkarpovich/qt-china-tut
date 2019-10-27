#include <QHBoxLayout>

#include "PageView.h"


PageView::PageView(QWidget *parent)
    : AbstractMainView(parent)
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    rootLayout->addWidget(container());
    setLayout(rootLayout);
}
