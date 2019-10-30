#ifndef GROUPTRAININGVIEW_H
#define GROUPTRAININGVIEW_H

#include <QList>
#include <QPushButton>
#include <QWidget>

#include <Entities/Training.h>
#include "GroupAbstractView.h"


class GroupTrainingView : public GroupAbstractView
{
    Q_OBJECT
    QPushButton *backBtn;
    QList<QPushButton *> btns;
public:
    explicit GroupTrainingView(GroupAbstractView *view);

signals:

public slots:
    void onBackBtnClicked();
    void onTrainingOptionClicked(Training::Type type);
};

#endif // GROUPTRAININGVIEW_H
