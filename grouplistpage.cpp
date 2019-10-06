#include <QHBoxLayout>
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
    groupListLbl = new QLabel("Наборы:");
    groupListWdg = new QListWidget;

    glSection->setMaximumWidth(250);
    glSectionLayout->addWidget(groupListLbl);
    glSectionLayout->addWidget(groupListWdg);
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

    wordListWdg = new WordListWidget;

    wlSectionLayout->addWidget(wordInputWgt);
    wlSectionLayout->addWidget(wordListWdg);

    layout()->addWidget(wlSection);
}

void GroupListPage::onWordInputReturnPressed()
{
    wordListWdg->appendWord(wordInput->text());
}
