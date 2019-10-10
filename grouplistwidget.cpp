#include "dbmanager.h"
#include "grouplistitem.h"
#include "grouplistwidget.h"

#include <QListWidgetItem>

GroupListWidget::GroupListWidget(QWidget* parent)
    : QListWidget(parent)
{
    groupList = DbManager::getAllGroups();
}

void GroupListWidget::addGroup(Group* gr)
{

}
