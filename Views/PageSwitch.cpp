#include "PageSwitch.h"
#include "ManagementView.h"
#include "LearningView.h"

void PageSwitch::setCurrentView(PageSwitch::ViewStates _viewState)
{
    viewState = _viewState;
    setCurrentIndex(viewState);
}

PageSwitch::PageSwitch(QWidget *parent)
    : QStackedWidget(parent), viewState(ManagementState)
{
    ManagementView* managementView = new ManagementView(this);
    LearningView *learningView = new LearningView(this);
    addWidget(managementView);
    addWidget(learningView);
    setCurrentIndex(viewState);
}

void PageSwitch::setManagementView()
{
    setCurrentView(ManagementState);
}

void PageSwitch::setLearningView()
{
    setCurrentView(LearningState);
}
