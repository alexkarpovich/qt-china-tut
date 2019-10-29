#ifndef ABSTRACTMAINVIEW_H
#define ABSTRACTMAINVIEW_H

#include <QStackedWidget>
#include <QWidget>
#include "AbstractPageView.h"

class AbstractMainView : public AbstractPageView
{
    Q_OBJECT
public:
    explicit AbstractMainView(QWidget *parent = nullptr);
    AbstractMainView(AbstractMainView *clone);

    void setManagementView();
    void setTrainingView();

private:

signals:

public slots:
};

#endif // ABSTRACTMAINVIEW_H
