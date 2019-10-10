#include <QHBoxLayout>
#include <QListWidgetItem>
#include "grouplistitem.h"
#include "grouplistpage.h"

GroupListPage::GroupListPage(QWidget *parent) : QWidget(parent)
{
    initLayout();
}

void GroupListPage::initLayout()
{
    QHBoxLayout* rootLayout = new QHBoxLayout;
    rootLayout->setSpacing(0);
    rootLayout->setMargin(0);
    setLayout(rootLayout);
    initGroupListSection();
    initWordListSection();
}

void GroupListPage::initGroupListSection()
{
    QWidget* glSection = new QWidget;
    QVBoxLayout* glSectionLayout = new QVBoxLayout;
    glSectionLayout->setSpacing(0);
    glSectionLayout->setMargin(0);
    QHBoxLayout* glTopLayout = new QHBoxLayout;
    glTopLayout->setMargin(3);
    groupListLbl = new QLabel("Наборы:");
    addGroupBtn = new QPushButton("+ добавить");
    glTopLayout->addWidget(groupListLbl);
    glTopLayout->addWidget(addGroupBtn);
    groupListView = new QListView;
    groupListModel = new GroupListModel();
    groupListView->setItemDelegate(new GroupListItem());
    groupListView->setModel(groupListModel);
    groupListView->setStyleSheet("GroupListWidget {border: none;} GroupListWidget::item:selected {background-color: #323232;}");
    connect(addGroupBtn, SIGNAL( clicked() ), SLOT(onAddGroupBtnClicked()));

    glSection->setMaximumWidth(250);
    glSectionLayout->addItem(glTopLayout);
    glSectionLayout->addWidget(groupListView);
    glSection->setLayout(glSectionLayout);

    layout()->addWidget(glSection);
}

void GroupListPage::initWordListSection()
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

    layout()->addWidget(wlSection);
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
