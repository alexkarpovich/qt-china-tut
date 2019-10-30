#ifndef ABSTRACTMAINVIEW_H
#define ABSTRACTMAINVIEW_H

#include <QStackedWidget>
#include <QWidget>
#include "AbstractPageView.h"

class ManagementView;
class TrainingView;

class AbstractMainView : public AbstractPageView
{
    Q_OBJECT
public:
    explicit AbstractMainView(QWidget *parent = nullptr);
    AbstractMainView(AbstractMainView *clone);

    void setManagementView(ManagementView *view = nullptr);
    void setTrainingView(TrainingView *view = nullptr);

private:

signals:

public slots:
};

#endif // ABSTRACTMAINVIEW_H
