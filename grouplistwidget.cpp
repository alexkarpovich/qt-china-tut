#include "grouplistitem.h"
#include "grouplistwidget.h"

#include <QListWidgetItem>

GroupListWidget::GroupListWidget(QWidget* parent)
    : QListWidget(parent)
{

}

void GroupListWidget::addGroup()
{
    GroupListItem* glItem = new GroupListItem;
    QListWidgetItem* item = new QListWidgetItem(this);
    item->setSizeHint(glItem->sizeHint());
    setItemWidget(item, glItem);
}
