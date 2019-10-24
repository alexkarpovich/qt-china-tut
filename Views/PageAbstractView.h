#ifndef PAGEABSTRACTVIEW_H
#define PAGEABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

class ManagementView;
class TrainingView;

class PageAbstractView : public QWidget
{
    Q_OBJECT
public:
    enum ViewState {
        ManagementState = 0,
        TrainingState = 1
    };

    explicit PageAbstractView(QWidget *parent = nullptr);
    PageAbstractView(PageAbstractView *clone);

    ViewState *getViewState() const;
    void setViewState(ViewState value);

    QStackedWidget *getContainer() const;
    void setContainer(QStackedWidget *value);

private:
    ViewState *viewState;
    QStackedWidget *container;
    ManagementView *managementView;
    TrainingView *trainingView;
signals:

public slots:
};

#endif // PAGEABSTRACTVIEW_H
