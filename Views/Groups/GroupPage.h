#ifndef GROUPPAGE_H
#define GROUPPAGE_H

#include <QStackedWidget>

#include "GroupEditView.h"
#include "GroupNotSelectedView.h"
#include "GroupTrainingView.h"


class GroupPage : public QStackedWidget
{
    enum ViewStates {
        NotSelectedState = 0,
        EditState = 1,
        TrainingState = 2
    };
    ViewStates viewState;
    GroupEditView *editView;
    GroupNotSelectedView *notSelectedView;
    GroupTrainingView *trainingView;
public:
    GroupPage(QWidget *parent = nullptr);
    void setGroups(QList<int> groupids);
};

#endif // GROUPPAGE_H
