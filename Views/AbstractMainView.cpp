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
    //setVisible(false);
}

void AbstractMainView::setManagementView()
{
    setCurrentWidget(typeid(ManagementView));
}

void AbstractMainView::setTrainingView()
{
    setCurrentWidget(typeid(TrainingView));
}
