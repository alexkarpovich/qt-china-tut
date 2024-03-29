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

    TrainingModel *getTrainingModel() const;

signals:

public slots:
    void onBackBtnClicked();
};

#endif // TRAININGVIEW_H
