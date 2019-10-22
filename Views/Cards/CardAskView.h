#ifndef CARDASKVIEW_H
#define CARDASKVIEW_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include <Models/CardModel.h>

class CardAskView : public QWidget
{
    Q_OBJECT

    CardModel *model;
    QLabel *textLbl;
    QPushButton *showBtn;
public:
    explicit CardAskView(CardModel *model, QWidget *parent = nullptr);

signals:

public slots:
    void onShowBtnClicked();
};

#endif // CARDASKVIEW_H
