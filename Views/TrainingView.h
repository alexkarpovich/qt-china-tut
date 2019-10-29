#ifndef TRAININGVIEW_H
#define TRAININGVIEW_H

#include <QWidget>
#include <Models/TrainingModel.h>
#include "AbstractMainView.h"
#include "Cards/CardView.h"

class TrainingView : public AbstractMainView
{
    Q_OBJECT

    TrainingModel *trainingModel;
    CardView *cardView;
public:
    explicit TrainingView(QList<int> groupids, Training::Type type, AbstractMainView *view = nullptr);

signals:

public slots:
    void activate();
};

#endif // TRAININGVIEW_H
