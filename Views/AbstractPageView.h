#ifndef ABSTRACTPAGEVIEW_H
#define ABSTRACTPAGEVIEW_H

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
    void setCurrentWidget(QWidget *widget);

    virtual void activate();

private:
    QStackedWidget *m_container;
signals:

public slots:
};

#endif // ABSTRACTPAGEVIEW_H
