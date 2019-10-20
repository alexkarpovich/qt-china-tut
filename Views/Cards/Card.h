#ifndef CARD_H
#define CARD_H

#include <QStackedWidget>
#include <QWidget>

class Card : public QWidget
{
    Q_OBJECT

    enum ViewState {
        AskState = 0,
        DetailState = 1
    };
    ViewState viewState;
    QStackedWidget *views;
    void setViewState(ViewState viewState);

public:
    explicit Card(QWidget *parent = nullptr);
    void setDetailView();

signals:

public slots:
};

#endif // CARD_H
