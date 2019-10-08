#include "dbmanager.h"
#include "grouplistitem.h"
#include "grouplistwidget.h"

#include <QListWidgetItem>

GroupListWidget::GroupListWidget(QWidget* parent)
    : QListWidget(parent)
{
    groupList = DbManager::getAllGroups();
}

void GroupListWidget::addGroup(const QString& name = "")
{
    GroupListItem* glItem = new GroupListItem;
    QListWidgetItem* item = new QListWidgetItem(this);
    item->setSizeHint(glItem->sizeHint());
    setItemWidget(item, glItem);
}
