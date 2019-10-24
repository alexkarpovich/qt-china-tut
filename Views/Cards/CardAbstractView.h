#ifndef CARDABSTRACTVIEW_H
#define CARDABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

#include <Models/CardModel.h>

class CardAskView;
class CardDetailView;
class CardCompleteView;

class CardAbstractView : public QWidget
{
    Q_OBJECT
public:
    enum ViewState {
        AskState = 0,
        DetailState = 1,
        CompleteState = 2
    };

    explicit CardAbstractView(QWidget *parent = nullptr);
    CardAbstractView(CardAbstractView *clone);

    ViewState *getViewState() const;
    void setViewState(ViewState value);

    CardModel *getModel() const;
    void setModel(CardModel *value);

    QStackedWidget *getContainer() const;

    void setAskView();
    void setDetailView();
    void setCompleteView();

private:
    ViewState *viewState;
    CardModel *model;
    QStackedWidget *container;
    CardAskView *askView;
    CardDetailView *detailView;
    CardCompleteView *completeView;

signals:

public slots:
};

#endif // CARDABSTRACTVIEW_H
