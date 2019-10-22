#include "GroupPage.h"
#include "GroupEditView.h"
#include "GroupNotSelectedView.h"
#include "GroupTrainingView.h"

GroupPage::GroupPage(QWidget *parent)
    : QStackedWidget(parent), viewState(NotSelectedState)
{
    notSelectedView = new GroupNotSelectedView;
    trainingView = new GroupTrainingView(this);
    editView = new GroupEditView(this);
    addWidget(notSelectedView);
    addWidget(editView);
    addWidget(trainingView);
    setCurrentIndex(viewState);
}
