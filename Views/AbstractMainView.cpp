#include "AbstractMainView.h"
#include "ManagementView.h"
#include "TrainingView.h"

AbstractMainView::AbstractMainView(QWidget *parent)
    : AbstractPageView(parent)
{
    setContainer(new QStackedWidget(this));
    managementView = new ManagementView(this);
    trainingView = new TrainingView(this);
    addPage(typeid(ManagementView), managementView);
    addPage(typeid(TrainingView), trainingView);
    setManagementView();
}

AbstractMainView::AbstractMainView(AbstractMainView *clone)
    : AbstractPageView(clone)
{
    setVisible(false);
}

void AbstractMainView::setManagementView()
{
    setCurrentWidget(typeid(ManagementView));
    activate();
}

void AbstractMainView::setTrainingView()
{
    setCurrentWidget(typeid(TrainingView));
    activate();
}

ManagementView *AbstractMainView::getManagementView() const
{
    return managementView;
}

TrainingView *AbstractMainView::getTrainingView() const
{
    return trainingView;
}
