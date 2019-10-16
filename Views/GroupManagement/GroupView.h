#ifndef GROUPVIEW_H
#define GROUPVIEW_H

#include <QStackedWidget>
#include <QWidget>
#include <Views/GroupManagement/GroupEditView.h>

class GroupView : public QWidget
{
    Q_OBJECT
    enum ViewStates {
        NotSelectedState = 0,
        EditState = 1
    };
    void buildLayout();
    void setViewState(ViewStates _viewState);
public:

    explicit GroupView(QWidget *parent = nullptr);
    void switchGroup(int groupId);

private:
    ViewStates viewState;
    QStackedWidget *views;
    GroupEditView *editView;

signals:

public slots:
};

#endif // GROUPVIEW_H
