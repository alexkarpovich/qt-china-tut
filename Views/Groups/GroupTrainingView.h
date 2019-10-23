#ifndef GROUPTRAININGVIEW_H
#define GROUPTRAININGVIEW_H

#include <QList>
#include <QPushButton>
#include <QWidget>

#include "GroupAbstractView.h"


class GroupTrainingView : public GroupAbstractView
{
    Q_OBJECT
    QList<QPushButton *> btns;
public:
    explicit GroupTrainingView(GroupAbstractView *view);

signals:

public slots:
};

#endif // GROUPTRAININGVIEW_H
