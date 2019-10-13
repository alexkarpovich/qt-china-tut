#include <Views/GroupManagement/GroupView.h>
#include <Views/GroupManagement/GroupNotSelectedView.h>

#include <QHBoxLayout>

GroupView::GroupView(QWidget *parent) : QWidget(parent)
{
    viewState = NotSelectedState;
    buildLayout();
}

void GroupView::setGroupId(int groupId)
{
    editView->setGroupId(groupId);
    setViewState(EditState);
}

void GroupView::buildLayout()
{
    QHBoxLayout *rootLayout = new QHBoxLayout;
    QWidget *notSelectedView = new GroupNotSelectedView;
    editView = new GroupEditView;
    views = new QStackedWidget;
    views->addWidget(notSelectedView);
    views->addWidget(editView);
    views->setCurrentIndex(viewState);
    rootLayout->addWidget(views);
    setLayout(rootLayout);
}

void GroupView::setViewState(GroupView::ViewStates _viewState)
{
    if (viewState != _viewState) {
        viewState = _viewState;
        views->setCurrentIndex(viewState);
    }
}
