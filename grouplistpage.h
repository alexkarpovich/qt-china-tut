#ifndef GROUPLISTPAGE_H
#define GROUPLISTPAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListView>
#include <QWidget>
#include <models/grouplistmodel.h>
#include "wordlistwidget.h"

class GroupListPage : public QWidget
{
    Q_OBJECT
    QPushButton* addGroupBtn;
    GroupListModel* groupListModel;
    QListView* groupListView;
    QLineEdit* wordInput;
    WordListWidget* wordListWgt;

    void buildControlsSection();
    void buildWorkSection();
    QWidget *buildGroupListSection();
    QWidget *buildWordListSection();
public:
    explicit GroupListPage(QWidget *parent = nullptr);
    void initLayout();

signals:

public slots:
    void onWordInputReturnPressed();
    void onAddGroupBtnClicked();
};

#endif // GROUPLISTPAGE_H
