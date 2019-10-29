#include "AbstractPageView.h"

AbstractPageView::AbstractPageView(QWidget *parent)
    : QWidget(parent), m_container(new QStackedWidget(parent)), m_pageMap(new QMap<std::type_index, AbstractPageView *>)
{
}

AbstractPageView::AbstractPageView(AbstractPageView *clone)
    : QWidget(clone)
{
    m_container = clone->container();
    m_pageMap = clone->pageMap();
}

QStackedWidget *AbstractPageView::container() const
{
    return m_container;
}

void AbstractPageView::setContainer(QStackedWidget *value)
{
    m_container = value;
}

void AbstractPageView::setCurrentWidget(std::type_index id)
{
    QWidget *current = m_container->currentWidget();

    if (current) {
        current->setVisible(false);
        m_container->removeWidget(current);
    }
    auto widget = page(id);
    m_container->addWidget(widget);
    m_container->setCurrentWidget(widget);
    widget->activate();
    widget->setVisible(true);
}

void AbstractPageView::activate()
{

}

QMap<std::type_index, AbstractPageView *> *AbstractPageView::pageMap() const
{
    return m_pageMap;
}

void AbstractPageView::addPage(std::type_index id, AbstractPageView *page)
{
    (*m_pageMap)[id] = page;
}

AbstractPageView *AbstractPageView::page(std::type_index id)
{
    return (*m_pageMap)[id];
}
