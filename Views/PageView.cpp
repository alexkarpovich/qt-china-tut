#include <QHBoxLayout>

#include "PageView.h"
#include "ManagementView.h"


PageView::PageView(QWidget *parent)
    : AbstractMainView(parent)
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    setManagementView();
    rootLayout->addWidget(container());
    setLayout(rootLayout);
}
