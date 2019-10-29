#ifndef CARDABSTRACTVIEW_H
#define CARDABSTRACTVIEW_H

#include <QWidget>

#include <Models/TrainingModel.h>
#include <Views/AbstractPageView.h>

class TrainingView;
class CardAskView;
class CardDetailView;
class CardCompleteView;

class CardAbstractView : public AbstractPageView
{
    Q_OBJECT
public:
    explicit CardAbstractView(CardAbstractView *clone);
    CardAbstractView(TrainingView *parent);

    TrainingModel *getModel() const;
    void setModel(TrainingModel *value);

    void activate();
    void setAskView(CardAskView *view = nullptr);
    void setDetailView(CardDetailView *view = nullptr);
    void setCompleteView(CardCompleteView *view = nullptr);

private:
    TrainingModel *model;
    CardAskView *askView = nullptr;
    CardDetailView *detailView = nullptr;
    CardCompleteView *completeView = nullptr;

signals:

public slots:
};

#endif // CARDABSTRACTVIEW_H
