#ifndef GROUPLISTPAGE_H
#define GROUPLISTPAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListView>
#include <QWidget>
#include <models/group_list_model.h>
#include <models/word_list_model.h>

class GroupListPage : public QWidget
{
    Q_OBJECT
    QPushButton* addGroupBtn;
    GroupListModel *groupListModel;
    WordListModel *wordListModel;
    QListView *groupListView;
    QListView *wordListView;
    QLineEdit* wordInput;

    void buildControlsSection();
    void buildWorkSection();
    QWidget *buildGroupListSection();
    QWidget *buildWordListSection();
    void buildLayout();
    void initializeWidgets();

public:
    explicit GroupListPage(QWidget *parent = nullptr);    

signals:

public slots:
    void onWordInputReturnPressed();
    void onAddGroupBtnClicked();
    void onGroupSelectionChanged(const QItemSelection& selection);
};

#endif // GROUPLISTPAGE_H
