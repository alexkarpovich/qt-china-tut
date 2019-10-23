#ifndef GROUPABSTRACTVIEW_H
#define GROUPABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

class GroupNotSelectedView;
class GroupEditView;
class GroupTrainingView;

class GroupAbstractView : public QWidget
{
    Q_OBJECT
    enum ViewStates {
        NotSelectedState = 0,
        EditState = 1,
        TrainingState = 2
    };
    ViewStates viewState;
    QList<int> groupids;
    QStackedWidget *container;
    GroupNotSelectedView *notSelectedView;
    GroupEditView *editView;
    GroupTrainingView *trainingView;

public:
    explicit GroupAbstractView(QWidget *parent = nullptr);
    GroupAbstractView(GroupAbstractView *clone);

    QStackedWidget *getContainer() const;
    void setContainer(QStackedWidget *value);
    void setNotSelectedView();
    void setEditView();
    void setTrainingView();

    QList<int> getGroupids() const;
    void setGroupids(const QList<int> &value);

signals:

public slots:
};

#endif // GROUPABSTRACTVIEW_H
