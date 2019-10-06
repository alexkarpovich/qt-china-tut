#ifndef GROUPLISTPAGE_H
#define GROUPLISTPAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QWidget>
#include "wordlistwidget.h"

class GroupListPage : public QWidget
{
    Q_OBJECT
    QLabel* groupListLbl;
    QListWidget* groupListWdg;
    QLineEdit* wordInput;
    WordListWidget* wordListWdg;

    void initGroupListSection();
    void initWordListSection();
public:
    explicit GroupListPage(QWidget *parent = nullptr);
    void initLayout();

signals:

public slots:
    void onWordInputReturnPressed();
};

#endif // GROUPLISTPAGE_H
