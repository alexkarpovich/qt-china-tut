#ifndef GROUPLISTPAGE_H
#define GROUPLISTPAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>
#include "wordlistwidget.h"

class GroupListPage : public QWidget
{
    Q_OBJECT
    QLabel* groupListLbl;
    QPushButton* addGroupBtn;
    QListWidget* groupListWgt;
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
