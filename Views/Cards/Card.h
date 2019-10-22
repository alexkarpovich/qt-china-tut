#ifndef CARD_H
#define CARD_H

#include <QStackedWidget>
#include <QWidget>

#include <Models/CardModel.h>

class Card : public QWidget
{
    Q_OBJECT

    enum ViewState {
        AskState = 0,
        DetailState = 1
    };
    ViewState viewState;
    CardModel *model;
    QStackedWidget *views;
    void setViewState(ViewState viewState);

public:
    explicit Card(QWidget *parent = nullptr);
    void setDetailView();

    CardModel *getModel() const;
    void setModel(CardModel *value);

signals:

public slots:
    void onModelChanged();
};

#endif // CARD_H
