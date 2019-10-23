#ifndef GROUPTRAININGVIEW_H
#define GROUPTRAININGVIEW_H

#include <QWidget>

#include "GroupAbstractView.h"


class GroupTrainingView : public GroupAbstractView
{
    Q_OBJECT
public:
    explicit GroupTrainingView(GroupAbstractView *view);

signals:

public slots:
};

#endif // GROUPTRAININGVIEW_H
