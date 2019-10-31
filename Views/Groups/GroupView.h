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
    explicit GroupView(ManagementView *view);

signals:

public slots:
    void onDataChanged();
};

#endif // GROUPVIEW_H
