#ifndef GROUPABSTRACTVIEW_H
#define GROUPABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

#include <Views/AbstractPageView.h>
#include <Views/AbstractMainView.h>

// Forward declaration to avoid cyclic inclusion
class GroupNotSelectedView;
class GroupEditView;
class GroupTrainingView;

class GroupAbstractView : public AbstractPageView
{
    Q_OBJECT

public:

    explicit GroupAbstractView(AbstractMainView *pageView);
    GroupAbstractView(GroupAbstractView *clone);

    void setNotSelectedView();
    void setEditView();
    void setTrainingView();

    QList<int> *getGroupids() const;
    void setGroupids(QList<int> value);

    AbstractMainView *getPageView() const;

    bool isNotSelectedView();

private:
    QList<int> *groupids;
    AbstractMainView *pageView;
    GroupNotSelectedView *notSelectedView;
    GroupEditView *editView;
    GroupTrainingView *trainingView;
signals:
    void dataChanged();

public slots:
    void activate() override;
};

#endif // GROUPABSTRACTVIEW_H
