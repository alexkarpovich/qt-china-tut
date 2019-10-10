#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include "grouplistitem.h"
#include "grouplistpage.h"

GroupListPage::GroupListPage(QWidget *parent) : QWidget(parent)
{
    initLayout();
}

void GroupListPage::initLayout()
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
    groupListView->setItemDelegate(new GroupListItem);
    groupListView->setEditTriggers(QAbstractItemView::DoubleClicked
                                    | QAbstractItemView::SelectedClicked);
    groupListView->setModel(groupListModel);
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

    wordListWgt = new WordListWidget;

    wlSectionLayout->addWidget(wordInputWgt);
    wlSectionLayout->addWidget(wordListWgt);

    return wlSection;
}

void GroupListPage::onWordInputReturnPressed()
{
    wordListWgt->appendWord(wordInput->text());
    wordInput->clear();
}

void GroupListPage::onAddGroupBtnClicked()
{
    Group *group = new Group;
    group->setId(1);
    group->setName("Test Group");
    groupListModel->addGroup(group);
}
