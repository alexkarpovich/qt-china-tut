#ifndef GROUPNOTSELECTEDVIEW_H
#define GROUPNOTSELECTEDVIEW_H

#include <QWidget>

#include "GroupAbstractView.h"


class GroupNotSelectedView : public GroupAbstractView
{
    Q_OBJECT
public:
    explicit GroupNotSelectedView(GroupAbstractView *view);

signals:

public slots:
};

#endif // GROUPNOTSELECTEDVIEW_H
