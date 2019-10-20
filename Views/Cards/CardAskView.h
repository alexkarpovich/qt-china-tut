#ifndef CARDASKVIEW_H
#define CARDASKVIEW_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class CardAskView : public QWidget
{
    Q_OBJECT

    QLabel *textLbl;
    QPushButton *showBtn;
public:
    explicit CardAskView(QWidget *parent = nullptr);

signals:

public slots:
    void onShowBtnClicked();
};

#endif // CARDASKVIEW_H
