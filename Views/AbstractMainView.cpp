#include "AbstractMainView.h"
#include "ManagementView.h"
#include "TrainingView.h"

AbstractMainView::AbstractMainView(QWidget *parent)
    : AbstractPageView(parent)
{
    setContainer(new QStackedWidget(this));
    managementView = new ManagementView(this);
    trainingView = new TrainingView(this);
    managementView->setVisible(false);
    trainingView->setVisible(false);
    setManagementView();
}

AbstractMainView::AbstractMainView(AbstractMainView *clone)
    : AbstractPageView(clone)
{
    managementView = clone->getManagementView();
    trainingView = clone->getTrainingView();
}

void AbstractMainView::setManagementView()
{
    setCurrentWidget(managementView);
    activate();
}

void AbstractMainView::setTrainingView()
{
    setCurrentWidget(trainingView);
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
