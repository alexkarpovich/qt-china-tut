#include "dbmanager.h"
#include "grouplistitem.h"

#include <QHBoxLayout>

Group *GroupListItem::getGroup() const
{
    return group;
}

void GroupListItem::setGroup(Group *value)
{
    group = value;
}

GroupListItem::GroupListItem(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* rootLayout = new QHBoxLayout;
    rootLayout->setMargin(5);
    groupNameInput = new QLineEdit;
    groupNameLbl = new ClickableLabel;
    removeGroupBtn = new QPushButton("✕");
    groupNameLbl->hide();
    rootLayout->addWidget(groupNameLbl);
    rootLayout->addWidget(groupNameInput);
    rootLayout->addWidget(removeGroupBtn);
    connect(groupNameLbl, SIGNAL(doubleClicked()), SLOT(onGroupNameLblDoubleClicked()));
    connect(groupNameInput, SIGNAL(returnPressed()), SLOT(onGroupNameInputReturnPressed()));
    setLayout(rootLayout);
}

void GroupListItem::onGroupNameInputReturnPressed()
{
    Group* gr = DbManager::insertGroup(groupNameInput->text());
    setGroup(gr);
    groupNameLbl->setText(group->getName());
    groupNameInput->hide();
    groupNameLbl->show();


}

void GroupListItem::onGroupNameLblDoubleClicked()
{
    groupNameInput->setText(group->getName());
    groupNameLbl->hide();
    groupNameInput->show();
}
