#ifndef PAGESWITCH_H
#define PAGESWITCH_H

#include <QStackedWidget>

class PageSwitch : public QStackedWidget
{
    enum ViewStates {
        ManagementState = 0,
        LearningState = 1
    };

    void setCurrentView(ViewStates _viewState);
public:
    PageSwitch(QWidget *parent = nullptr);
    void setManagementView();
    void setLearningView();
private:
    ViewStates viewState;
};

#endif // PAGESWITCH_H
