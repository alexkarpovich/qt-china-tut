#ifndef TRAININGVIEW_H
#define TRAININGVIEW_H

#include <QWidget>
#include "PageAbstractView.h"
#include "Cards/CardView.h"

class TrainingView : public PageAbstractView
{
    Q_OBJECT

    CardView *cardView;
public:
    explicit TrainingView(PageAbstractView *view = nullptr);

signals:

public slots:
    virtual void activate();
};

#endif // TRAININGVIEW_H
