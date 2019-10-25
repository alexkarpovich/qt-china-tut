#include "PageAbstractView.h"
#include "ManagementView.h"
#include "TrainingView.h"

PageAbstractView::PageAbstractView(QWidget *parent)
    : QWidget(parent), viewState(new ViewState)
{
    *viewState = ManagementState;
    container = new QStackedWidget(this);
    managementView = new ManagementView(this);
    trainingView = new TrainingView(this);
    container->addWidget(managementView);
    container->addWidget(trainingView);
    container->setCurrentIndex(*viewState);
}

PageAbstractView::PageAbstractView(PageAbstractView *clone)
    : QWidget(clone)
{
    viewState = clone->getViewState();
    container = clone->getContainer();
}

PageAbstractView::ViewState *PageAbstractView::getViewState() const
{
    return viewState;
}

void PageAbstractView::setViewState(ViewState value)
{
    *viewState = value;
    container->setCurrentIndex(value);
}

QStackedWidget *PageAbstractView::getContainer() const
{
    return container;
}

void PageAbstractView::setContainer(QStackedWidget *value)
{
    container = value;
}

void PageAbstractView::activate()
{
    PageAbstractView *view = qobject_cast<PageAbstractView *>(container->currentWidget());
    view->activate();
}

void PageAbstractView::setManagementView()
{
    setViewState(ManagementState);
    activate();
}

void PageAbstractView::setTrainingView()
{
    setViewState(TrainingState);
    activate();
}
