#ifndef GROUPLISTITEM_H
#define GROUPLISTITEM_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "shared/clickablelabel.h"

class GroupListItem : public QWidget
{
    Q_OBJECT
    bool isEditing = true;
    QString groupName;
    QWidget* groupNameWdg;
    QLineEdit* groupNameInput;
    ClickableLabel* groupNameLbl;
    QPushButton* removeGroupBtn;

public:
    explicit GroupListItem(QWidget *parent = nullptr);    

signals:

public slots:
    void onGroupNameInputReturnPressed();
    void onGroupNameLblDoubleClicked();
};

#endif // GROUPLISTITEM_H
