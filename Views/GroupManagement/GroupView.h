#ifndef GROUPVIEW_H
#define GROUPVIEW_H

#include <QStackedWidget>
#include <QWidget>
#include <Views/GroupManagement/GroupPage.h>
#include <Views/GroupManagement/GroupEditView.h>
#include <Views/GroupManagement/GroupTrainingView.h>

class GroupView : public QWidget
{
    Q_OBJECT
    void buildLayout();
public:

    explicit GroupView(QWidget *parent = nullptr);
    void setGroups(QList<int> groupids);

private:
    QList<int> groupids;

    GroupPage *page;

signals:

public slots:
};

#endif // GROUPVIEW_H
