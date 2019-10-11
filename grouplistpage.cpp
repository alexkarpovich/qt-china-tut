#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include "dbmanager.h"
#include "group_list_item.h"
#include "grouplistpage.h"
#include "word_list_item.h"

GroupListPage::GroupListPage(QWidget *parent) : QWidget(parent)
{
    buildLayout();
    initializeWidgets();
}

void GroupListPage::buildLayout()
{
    QVBoxLayout* rootLayout = new QVBoxLayout;
    rootLayout->setSpacing(0);
    rootLayout->setMargin(0);
    setLayout(rootLayout);
    buildControlsSection();
    buildWorkSection();
}

void GroupListPage::buildControlsSection()
{
    QHBoxLayout *controlsLayout = new QHBoxLayout;
    addGroupBtn = new QPushButton("+ набор");
    controlsLayout->addWidget(addGroupBtn);
    QVBoxLayout* rootLayout = qobject_cast<QVBoxLayout*>(layout());
    rootLayout->addLayout(controlsLayout);
}

void GroupListPage::buildWorkSection()
{
    QHBoxLayout *workSectionLayout = new QHBoxLayout;
    workSectionLayout->addWidget(buildGroupListSection());
    workSectionLayout->addWidget(buildWordListSection());

    QVBoxLayout* rootLayout = qobject_cast<QVBoxLayout*>(layout());
    rootLayout->addLayout(workSectionLayout);
}

QWidget *GroupListPage::buildGroupListSection()
{
    QWidget* glSection = new QWidget;
    QVBoxLayout* glSectionLayout = new QVBoxLayout;
    glSectionLayout->setSpacing(0);
    glSectionLayout->setMargin(0);
    groupListView = new QListView;
    groupListModel = new GroupListModel();
    groupListView->setFrameStyle(QFrame::NoFrame);
    groupListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    groupListView->setItemDelegate(new GroupListItem);
    groupListView->setEditTriggers(QAbstractItemView::DoubleClicked
                                    | QAbstractItemView::SelectedClicked);
    groupListView->setModel(groupListModel);
    connect(groupListView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(onGroupSelectionChanged(QItemSelection)));
    //groupListView->setStyleSheet("GroupListWidget {border: none;} GroupListWidget::item:selected {background-color: #323232;}");
    connect(addGroupBtn, SIGNAL(clicked()), SLOT(onAddGroupBtnClicked()));

    glSection->setMaximumWidth(250);
    glSectionLayout->addWidget(groupListView);
    glSection->setLayout(glSectionLayout);

    return glSection;
}

QWidget *GroupListPage::buildWordListSection()
{
    QWidget* wlSection = new QWidget;
    QVBoxLayout* wlSectionLayout = new QVBoxLayout;
    QWidget* wordInputWgt = new QWidget;
    QHBoxLayout* wiLayout = new QHBoxLayout;
    wiLayout->setMargin(0);
    QSpacerItem* leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
    QSpacerItem* rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
    wordInput = new QLineEdit;
    wordInput->setPlaceholderText("Введите слово...");
    wordInput->setStyleSheet("padding: 3px 10px;");
    wordInput->setMinimumWidth(100);
    connect(wordInput, SIGNAL( returnPressed() ), SLOT(onWordInputReturnPressed()));
    wiLayout->addItem(leftSpacer);
    wiLayout->addWidget(wordInput);
    wiLayout->addItem(rightSpacer);
    wordInputWgt->setMaximumHeight(48);
    wordInputWgt->setLayout(wiLayout);
    wlSection->setLayout(wlSectionLayout);

    wordListView = new QListView;
    wordListModel = new WordListModel;
    wordListView->setFrameStyle(QFrame::NoFrame);
    wordListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    wordListView->setItemDelegate(new WordListItem);
    wordListView->setEditTriggers(QAbstractItemView::DoubleClicked
                                    | QAbstractItemView::SelectedClicked);
    wordListView->setModel(wordListModel);
    wlSectionLayout->addWidget(wordInputWgt);
    wlSectionLayout->addWidget(wordListView);

    return wlSection;
}

void GroupListPage::initializeWidgets()
{
    QList<Group*> groups = DbManager::getAllGroups();
    groupListModel->setGroups(groups);
}

void GroupListPage::onWordInputReturnPressed()
{
    QModelIndex index = groupListView->currentIndex();
    int groupId = index.data(GroupListModel::IdRole).toInt();
    Word *wrd = DbManager::insertGroupWord(groupId, wordInput->text());
    wordListModel->addWord(wrd);
    wordInput->clear();
}

void GroupListPage::onAddGroupBtnClicked()
{
    Group *group = new Group;
    group->setName("<Задайте имя группы>");
    groupListModel->addGroup(group);
}

void GroupListPage::onGroupSelectionChanged(const QItemSelection& selection)
{
    QModelIndex index = selection.indexes().first();
    int groupId = index.data(GroupListModel::IdRole).toInt();
    qDebug() << QString("Group selection changed %1").arg(groupId);

    QList<Word*> words = DbManager::getAllGroupWords(groupId);
    wordListModel->setWords(words);
}
