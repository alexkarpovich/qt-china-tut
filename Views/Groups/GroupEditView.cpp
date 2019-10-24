#include <QDebug>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHeaderView>

#include <Dao/TrainingDao.h>
#include <Entities/Training.h>
#include <Views/Words/WordItemDelegate.h>
#include "GroupEditView.h"


GroupEditView::GroupEditView(GroupAbstractView *view)
    : GroupAbstractView(view)
{
    buildLayout();
    connect(view, SIGNAL(dataChanged()), this, SLOT(onDataChanged()));
}

void GroupEditView::onDataChanged()
{
    if (*getViewState() == NotSelectedState) {
        setEditView();
    }

    wordModel = new WordModel(*getGroupids());
    wordTableView->setModel(wordModel);
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
    connect(wordInput, SIGNAL(returnPressed()), SLOT(onWordInputReturnPressed()));
    wiLayout->addItem(leftSpacer);
    wiLayout->addWidget(wordInput);
    wiLayout->addItem(rightSpacer);
    wordInputWgt->setMaximumHeight(48);
    wordInputWgt->setLayout(wiLayout);
    setLayout(wlSectionLayout);

    wordTableView = new QTableView;
    wordModel = new WordModel(*getGroupids());
    wordTableView->setFrameStyle(QFrame::NoFrame);
    wordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    wordTableView->horizontalHeader()->setStretchLastSection(true);
    wordTableView->horizontalHeader()->setFixedHeight(18);
    wordTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    wordTableView->setItemDelegate(new WordItemDelegate);
    wordTableView->setEditTriggers(QAbstractItemView::DoubleClicked
                                    | QAbstractItemView::SelectedClicked);
    wordTableView->setModel(wordModel);

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    startTrainingBtn = new QPushButton("Тренировка");
    startExamineBtn = new QPushButton("Экзамен");

    connect(startTrainingBtn, SIGNAL(clicked()), SLOT(onStartTrainingClicked()));

    controlsLayout->addWidget(startExamineBtn);
    controlsLayout->addWidget(startTrainingBtn);
    wlSectionLayout->addWidget(wordInputWgt);
    wlSectionLayout->addWidget(wordTableView);
    wlSectionLayout->addLayout(controlsLayout);
}

void GroupEditView::onWordInputReturnPressed()
{
    wordModel->addWord(wordInput->text());
    wordInput->clear();
}

void GroupEditView::onStartTrainingClicked()
{    
    setTrainingView();
}

