#ifndef TRAININGVIEW_H
#define TRAININGVIEW_H

#include <QWidget>
#include "AbstractMainView.h"
#include "Cards/CardView.h"

class TrainingView : public AbstractMainView
{
    Q_OBJECT

    CardView *cardView;
public:
    explicit TrainingView(AbstractMainView *view = nullptr);

signals:

public slots:
    void activate();
};

#endif // TRAININGVIEW_H
