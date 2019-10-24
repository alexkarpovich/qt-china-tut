#ifndef CARDABSTRACTVIEW_H
#define CARDABSTRACTVIEW_H

#include <QStackedWidget>
#include <QWidget>

#include <Models/CardModel.h>

class CardAskView;
class CardDetailView;

class CardAbstractView : public QWidget
{
    Q_OBJECT
public:
    enum ViewState {
        AskState = 0,
        DetailState = 1
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

private:
    ViewState *viewState;
    CardModel *model;
    QStackedWidget *container;
    CardAskView *askView;
    CardDetailView *detailView;

signals:

public slots:
};

#endif // CARDABSTRACTVIEW_H
