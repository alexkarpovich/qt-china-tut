#ifndef MANAGEMENTVIEW_H
#define MANAGEMENTVIEW_H

#include <QListView>
#include <QPushButton>
#include <QWidget>

#include <models/GroupListModel.h>
#include <Views/GroupManagement/GroupView.h>

class ManagementView : public QWidget
{
    Q_OBJECT
    QPushButton* addGroupBtn;
    GroupListModel *groupListModel;
    QListView *groupListView;
    GroupView *groupView;

    void buildControlsSection();
    void buildWorkSection();
    QWidget *buildGroupListSection();
    void buildLayout();
    void initializeWidgets();
public:
    explicit ManagementView(QWidget *parent = nullptr);

public slots:
    void onAddGroupBtnClicked();
    void onGroupSelectionChanged(const QItemSelection& selection);
};

#endif // MANAGEMENTVIEW_H
