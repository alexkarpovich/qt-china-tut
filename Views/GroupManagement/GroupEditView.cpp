#include <QLineEdit>
#include <QVBoxLayout>
#include <QHeaderView>

#include <Views/GroupManagement/GroupEditView.h>
#include <Views/WordManagement/WordItemDelegate.h>

GroupEditView::GroupEditView(QWidget *parent)
    : QWidget(parent)
{
    buildLayout();
}

void GroupEditView::setGroupId(int _groupId)
{
    groupId = _groupId;
//    QList<Word*> words = DbManager::getAllGroupWords(groupId);
//    wordTableModel->setWords(words);
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
    wordModel = new WordModel;
    wordTableView->setFrameStyle(QFrame::NoFrame);
    wordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //wordTableView->horizontalHeader()->hide();
    wordTableView->horizontalHeader()->setStretchLastSection(true);
    wordTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    wordTableView->setItemDelegate(new WordItemDelegate);
    wordTableView->setEditTriggers(QAbstractItemView::DoubleClicked
                                    | QAbstractItemView::SelectedClicked);
    wordTableView->setModel(wordModel);
    wlSectionLayout->addWidget(wordInputWgt);
    wlSectionLayout->addWidget(wordTableView);
}

void GroupEditView::onWordInputReturnPressed()
{
    wordModel->addWord(wordInput->text());
    wordInput->clear();
}

