#ifndef GROUPLISTPAGE_H
#define GROUPLISTPAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "grouplistwidget.h"
#include "wordlistwidget.h"

class GroupListPage : public QWidget
{
    Q_OBJECT
    QLabel* groupListLbl;
    QPushButton* addGroupBtn;
    GroupListWidget* groupListWgt;
    QLineEdit* wordInput;
    WordListWidget* wordListWgt;

    void initGroupListSection();
    void initWordListSection();
public:
    explicit GroupListPage(QWidget *parent = nullptr);
    void initLayout();

signals:

public slots:
    void onWordInputReturnPressed();
    void onAddGroupBtnClicked();
};

#endif // GROUPLISTPAGE_H
