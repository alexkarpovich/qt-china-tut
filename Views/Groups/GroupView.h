#ifndef GROUPVIEW_H
#define GROUPVIEW_H

#include <QStackedWidget>
#include <QWidget>
#include "GroupPage.h"
#include "GroupEditView.h"
#include "GroupTrainingView.h"

class GroupView : public QWidget
{
    Q_OBJECT
    void buildLayout();
public:

    explicit GroupView(QWidget *parent = nullptr);
    void setGroups(QList<int> groupids);

private:
    QList<int> groupids;

    GroupPage *page;

signals:

public slots:
};

#endif // GROUPVIEW_H
