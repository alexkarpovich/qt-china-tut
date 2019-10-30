#include "AbstractMainView.h"
#include "ManagementView.h"
#include "TrainingView.h"

AbstractMainView::AbstractMainView(QWidget *parent)
    : AbstractPageView(parent)
{
    setContainer(new QStackedWidget(this));
}

AbstractMainView::AbstractMainView(AbstractMainView *clone)
    : AbstractPageView(clone)
{
}

void AbstractMainView::setManagementView(ManagementView *view)
{
    ManagementView *existingView = static_cast<ManagementView *>(page(typeid(ManagementView)));

    if (!existingView && !view) {
        view = new ManagementView(this);
    }

    if (!existingView) {
        addPage(typeid(ManagementView), view);
    }

    setCurrentWidget(typeid(ManagementView));
}

void AbstractMainView::setTrainingView(TrainingView *view)
{    
    TrainingView *existingView = static_cast<TrainingView *>(page(typeid(TrainingView)));

    if (!existingView) {
        addPage(typeid(TrainingView), view);
    }

    setCurrentWidget(typeid(TrainingView));
}
