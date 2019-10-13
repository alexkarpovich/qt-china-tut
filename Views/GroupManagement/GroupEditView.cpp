#include <QLineEdit>
#include <QVBoxLayout>
#include <QHeaderView>

#include <dbmanager.h>
#include <Views/GroupManagement/GroupEditView.h>
#include <Views/WordManagement/WordListItemDelegate.h>

GroupEditView::GroupEditView(QWidget *parent)
    : QWidget(parent)
{
    buildLayout();
}

void GroupEditView::setGroupId(int _groupId)
{
    groupId = _groupId;
    QList<Word*> words = DbManager::getAllGroupWords(groupId);
    wordTableModel->setWords(words);
}

void GroupEditView::buildLayout()
{
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
    setLayout(wlSectionLayout);

    wordTableView = new QTableView;
    wordTableModel = new WordTableModel;
    wordTableView->setFrameStyle(QFrame::NoFrame);
    wordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //wordTableView->horizontalHeader()->hide();
    wordTableView->horizontalHeader()->setStretchLastSection(true);
    wordTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    wordTableView->setItemDelegate(new WordListItemDelegate);
    wordTableView->setEditTriggers(QAbstractItemView::DoubleClicked
                                    | QAbstractItemView::SelectedClicked);
    wordTableView->setModel(wordTableModel);
    wlSectionLayout->addWidget(wordInputWgt);
    wlSectionLayout->addWidget(wordTableView);
}

void GroupEditView::onWordInputReturnPressed()
{
    Word *wrd = DbManager::insertGroupWord(groupId, wordInput->text());
    wordTableModel->addWord(wrd);
    wordInput->clear();
}

