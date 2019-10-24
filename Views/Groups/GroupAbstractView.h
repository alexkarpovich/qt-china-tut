#ifndef GROUPABSTRACTVIEW_H
#define GROUPABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

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

    explicit GroupAbstractView(QWidget *parent = nullptr);
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
private:
    ViewState *viewState;
    QList<int> *groupids;
    QStackedWidget *container;
    GroupNotSelectedView *notSelectedView;
    GroupEditView *editView;
    GroupTrainingView *trainingView;
signals:
    void dataChanged();

public slots:
};

#endif // GROUPABSTRACTVIEW_H
