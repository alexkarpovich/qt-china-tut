#ifndef GROUPVIEW_H
#define GROUPVIEW_H

#include <QStackedWidget>
#include <QWidget>
#include "GroupAbstractView.h"
#include "GroupNotSelectedView.h"
#include "GroupEditView.h"
#include "GroupTrainingView.h"

class GroupView : public GroupAbstractView
{
    Q_OBJECT

    GroupEditView *editView;
    GroupNotSelectedView *notSelectedView;
    GroupTrainingView *trainingView;

    void buildLayout();
public:
    explicit GroupView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // GROUPVIEW_H
