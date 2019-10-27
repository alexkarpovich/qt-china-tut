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

    void setManagementView();
    void setTrainingView();

    ManagementView *getManagementView() const;

    TrainingView *getTrainingView() const;

private:
    ManagementView *managementView;
    TrainingView *trainingView;
signals:

public slots:
};

#endif // ABSTRACTMAINVIEW_H
