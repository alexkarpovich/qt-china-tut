#include "AbstractPageView.h"

AbstractPageView::AbstractPageView(QWidget *parent)
    : QWidget(parent), m_container(new QStackedWidget(parent))
{

}

AbstractPageView::AbstractPageView(AbstractPageView *clone)
    : QWidget(clone)
{
    m_container = clone->container();
}

QStackedWidget *AbstractPageView::container() const
{
    return m_container;
}

void AbstractPageView::setContainer(QStackedWidget *value)
{
    m_container = value;
}

void AbstractPageView::setCurrentWidget(QWidget *widget)
{
    QWidget *current = m_container->currentWidget();

    if (current) {
        current->setVisible(false);
        m_container->removeWidget(current);
    }

    m_container->addWidget(widget);
    m_container->setCurrentWidget(widget);
    widget->setVisible(true);
}

void AbstractPageView::activate()
{
    AbstractPageView *view = qobject_cast<AbstractPageView *>(m_container->currentWidget());
    view->activate();
}
