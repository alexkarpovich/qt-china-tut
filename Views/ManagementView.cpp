#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>

#include <Dao/GroupDao.h>

#include <Views/ManagementView.h>
#include <Views/GroupManagement/GroupListItemDelegate.h>

ManagementView::ManagementView(QWidget *parent)
    : QWidget(parent)
{
    buildLayout();
}

void ManagementView::buildLayout()
{
    QVBoxLayout* rootLayout = new QVBoxLayout;
    rootLayout->setSpacing(0);
    rootLayout->setMargin(0);
    setLayout(rootLayout);
    buildControlsSection();
    buildWorkSection();
}

void ManagementView::buildControlsSection()
{
    QHBoxLayout *controlsLayout = new QHBoxLayout;
    addGroupBtn = new QPushButton("+ набор");
    controlsLayout->addWidget(addGroupBtn);
    QVBoxLayout* rootLayout = qobject_cast<QVBoxLayout*>(layout());
    rootLayout->addLayout(controlsLayout);
}

void ManagementView::buildWorkSection()
{
    QHBoxLayout *workSectionLayout = new QHBoxLayout;
    groupView = new GroupView;
    workSectionLayout->addWidget(buildGroupListSection());
    workSectionLayout->addWidget(groupView);

    QVBoxLayout* rootLayout = qobject_cast<QVBoxLayout*>(layout());
    rootLayout->addLayout(workSectionLayout);
}

QWidget *ManagementView::buildGroupListSection()
{
    QWidget* glSection = new QWidget;
    QVBoxLayout* glSectionLayout = new QVBoxLayout;
    glSectionLayout->setSpacing(0);
    glSectionLayout->setMargin(0);
    groupListView = new QListView;
    groupModel = new GroupModel();
    groupListView->setFrameStyle(QFrame::NoFrame);
    groupListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    groupListView->setItemDelegate(new GroupListItemDelegate);
    groupListView->setEditTriggers(QAbstractItemView::DoubleClicked
                                    | QAbstractItemView::SelectedClicked);
    groupListView->setModel(groupModel);
    connect(groupListView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(onGroupSelectionChanged(QItemSelection)));
    //groupListView->setStyleSheet("GroupListWidget {border: none;} GroupListWidget::item:selected {background-color: #323232;}");
    connect(addGroupBtn, SIGNAL(clicked()), SLOT(onAddGroupBtnClicked()));

    glSection->setMaximumWidth(250);
    glSectionLayout->addWidget(groupListView);
    glSection->setLayout(glSectionLayout);

    return glSection;
}

void ManagementView::onAddGroupBtnClicked()
{
    groupModel->addGroup("неизвестная группа");
}

void ManagementView::onGroupSelectionChanged(const QItemSelection& selection)
{
    QModelIndex index = selection.indexes().first();

    if (index.isValid()) {
        int groupId = index.data(GroupModel::IdRole).toInt();
        qDebug() << QString("Group selection changed %1").arg(groupId);
        groupView->switchGroup(groupId);
    }
}
