#include "grouplistitem.h"

#include <QHBoxLayout>

GroupListItem::GroupListItem(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* rootLayout = new QHBoxLayout;
    groupNameInput = new QLineEdit;
    groupNameLbl = new ClickableLabel;
    removeGroupBtn = new QPushButton("✕");
    removeGroupBtn->setFixedWidth(24);
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
    groupName = groupNameInput->text();
    groupNameLbl->setText(groupName);
    groupNameInput->hide();
    groupNameLbl->show();

}

void GroupListItem::onGroupNameLblDoubleClicked()
{
    groupNameInput->setText(groupName);
    groupNameLbl->hide();
    groupNameInput->show();
}
