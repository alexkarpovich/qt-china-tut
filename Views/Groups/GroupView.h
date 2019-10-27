#ifndef GROUPVIEW_H
#define GROUPVIEW_H

#include <QWidget>
#include <Views/AbstractMainView.h>
#include "GroupAbstractView.h"

class GroupView : public GroupAbstractView
{
    Q_OBJECT

    void buildLayout();
public:
    explicit GroupView(AbstractMainView *pageView);

signals:

public slots:
};

#endif // GROUPVIEW_H
