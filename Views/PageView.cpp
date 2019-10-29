#include <QHBoxLayout>

#include "PageView.h"
#include "ManagementView.h"


PageView::PageView(QWidget *parent)
    : AbstractMainView(parent)
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    ManagementView *managementView = new ManagementView(this);
    addPage(typeid(ManagementView), managementView);
    setManagementView();
    rootLayout->addWidget(container());
    setLayout(rootLayout);
}
