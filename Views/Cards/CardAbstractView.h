#ifndef CARDABSTRACTVIEW_H
#define CARDABSTRACTVIEW_H

#include <QWidget>

#include <Models/CardModel.h>
#include <Views/AbstractPageView.h>

class CardAskView;
class CardDetailView;
class CardCompleteView;

class CardAbstractView : public AbstractPageView
{
    Q_OBJECT
public:
    explicit CardAbstractView(AbstractPageView *parent);
    CardAbstractView(CardAbstractView *clone);

    CardModel *getModel() const;
    void setModel(CardModel *value);

    void activate();
    void setAskView();
    void setDetailView();
    void setCompleteView();

    CardAskView *getAskView() const;

    CardDetailView *getDetailView() const;

    CardCompleteView *getCompleteView() const;

private:
    CardModel *model;
    CardAskView *askView;
    CardDetailView *detailView;
    CardCompleteView *completeView;

signals:

public slots:
};

#endif // CARDABSTRACTVIEW_H
