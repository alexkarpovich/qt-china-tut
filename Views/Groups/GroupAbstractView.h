#ifndef GROUPABSTRACTVIEW_H
#define GROUPABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

#include <Views/AbstractPageView.h>
#include <Views/AbstractMainView.h>

#include <Models/GroupModel.h>


class GroupAbstractView : public AbstractPageView
{
    Q_OBJECT

public:
    GroupAbstractView(ManagementView *parent);
    GroupAbstractView(GroupAbstractView *clone);

    void setNotSelectedView();
    void setEditView();
    void setTrainingView();

    QList<int> *getGroupids() const;
    void setGroupids(QList<int> value);

    AbstractMainView *getPageView() const;

    bool isNotSelectedView();

    GroupModel *getGroupModel() const;
    void setGroupModel(GroupModel *value);

private:
    QList<int> *groupids;
    GroupModel *groupModel;
    AbstractMainView *pageView;
signals:
    void dataChanged();

public slots:
};

#endif // GROUPABSTRACTVIEW_H
