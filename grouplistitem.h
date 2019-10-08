#ifndef GROUPLISTITEM_H
#define GROUPLISTITEM_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <models/group.h>
#include "shared/clickablelabel.h"

class GroupListItem : public QWidget
{
    Q_OBJECT
    bool isEditing = true;
    Group *group;
    QWidget* groupNameWdg;
    QLineEdit* groupNameInput;
    ClickableLabel* groupNameLbl;
    QPushButton* removeGroupBtn;

public:
    explicit GroupListItem(QWidget *parent = nullptr);    

    Group *getGroup() const;
    void setGroup(Group *value);

signals:

public slots:
    void onGroupNameInputReturnPressed();
    void onGroupNameLblDoubleClicked();
};

#endif // GROUPLISTITEM_H
