#ifndef TRAININGVIEW_H
#define TRAININGVIEW_H

#include <QWidget>
#include "PageAbstractView.h"

class TrainingView : public PageAbstractView
{
    Q_OBJECT
public:
    explicit TrainingView(PageAbstractView *view = nullptr);

signals:

public slots:
};

#endif // TRAININGVIEW_H
