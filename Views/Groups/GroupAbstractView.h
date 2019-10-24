#ifndef GROUPABSTRACTVIEW_H
#define GROUPABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

#include <Views/PageAbstractView.h>

// Forward declaration to avoid cyclic inclusion
class GroupNotSelectedView;
class GroupEditView;
class GroupTrainingView;

class GroupAbstractView : public QWidget
{
    Q_OBJECT
public:
    enum ViewState {
        NotSelectedState = 0,
        EditState = 1,
        TrainingState = 2
    };

    explicit GroupAbstractView(PageAbstractView *pageView);
    GroupAbstractView(GroupAbstractView *clone);

    QStackedWidget *getContainer() const;
    void setContainer(QStackedWidget *value);
    void setNotSelectedView();
    void setEditView();
    void setTrainingView();

    QList<int> *getGroupids() const;
    void setGroupids(QList<int> value);

    ViewState *getViewState() const;
    void setViewState(ViewState value);
    PageAbstractView *getPageView() const;

private:
    ViewState *viewState;
    QList<int> *groupids;
    QStackedWidget *container;
    PageAbstractView *pageView;
    GroupNotSelectedView *notSelectedView;
    GroupEditView *editView;
    GroupTrainingView *trainingView;
signals:
    void dataChanged();

public slots:
};

#endif // GROUPABSTRACTVIEW_H
