#ifndef CARDDETAILVIEW_H
#define CARDDETAILVIEW_H

#include <QWidget>

#include <Models/CardModel.h>

class CardDetailView : public QWidget
{
    Q_OBJECT

    CardModel *model;
public:
    explicit CardDetailView(CardModel *model, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // CARDDETAILVIEW_H
