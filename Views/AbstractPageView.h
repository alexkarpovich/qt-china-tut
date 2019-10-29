#ifndef ABSTRACTPAGEVIEW_H
#define ABSTRACTPAGEVIEW_H

#include <typeindex>
#include <typeinfo>
#include <QMap>
#include <QStackedWidget>
#include <QWidget>

class AbstractPageView : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractPageView(QWidget *parent = nullptr);
    AbstractPageView(AbstractPageView *clone);

    QStackedWidget *container() const;
    void setContainer(QStackedWidget *value);
    void setCurrentWidget(std::type_index id);

    QMap<std::type_index, AbstractPageView *> *pageMap() const;
    void addPage(std::type_index id, AbstractPageView *page);
    AbstractPageView *page(std::type_index id);


private:
    QStackedWidget *m_container;
    QMap<std::type_index, AbstractPageView *> *m_pageMap;
signals:

public slots:
};

#endif // ABSTRACTPAGEVIEW_H
