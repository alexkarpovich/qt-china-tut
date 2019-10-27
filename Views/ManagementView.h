#ifndef MANAGEMENTVIEW_H
#define MANAGEMENTVIEW_H


#include <QListView>
#include <QPushButton>
#include <QWidget>

#include <Models/GroupModel.h>
#include "AbstractMainView.h"
#include "Groups/GroupView.h"

class ManagementView : public AbstractMainView
{
    Q_OBJECT
    QPushButton* addGroupBtn;
    GroupModel *groupModel;
    QListView *groupListView;
    GroupView *groupView;

    void buildControlsSection();
    void buildWorkSection();
    QWidget *buildGroupListSection();
    void buildLayout();
    void initializeWidgets();
public:
    explicit ManagementView(AbstractMainView *view);

public slots:
    virtual void activate();
    void onAddGroupBtnClicked();
    void onGroupSelectionChanged(const QItemSelection& selection);
};

#endif // MANAGEMENTVIEW_H
