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
    setLayout(new QHBoxLayout);
    initGroupListSection();
    initWordListSection();
}

void GroupListPage::initGroupListSection()
{
    QWidget* glSection = new QWidget;
    QVBoxLayout* glSectionLayout = new QVBoxLayout;
    QHBoxLayout* glTopLayout = new QHBoxLayout;
    groupListLbl = new QLabel("Наборы:");
    addGroupBtn = new QPushButton("+ добавить");
    glTopLayout->addWidget(groupListLbl);
    glTopLayout->addWidget(addGroupBtn);
    groupListWgt = new QListWidget;
    connect(addGroupBtn, SIGNAL( clicked() ), SLOT(onAddGroupBtnClicked()));

    glSection->setMaximumWidth(250);
    glSectionLayout->addItem(glTopLayout);
    glSectionLayout->addWidget(groupListWgt);
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
    GroupListItem* glItem = new GroupListItem;
    QListWidgetItem* item = new QListWidgetItem( groupListWgt );
    item->setSizeHint( glItem->sizeHint() );
    groupListWgt->setItemWidget( item, glItem );
}
