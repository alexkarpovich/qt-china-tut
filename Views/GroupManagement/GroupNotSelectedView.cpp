#include "GroupNotSelectedView.h"

#include <QVBoxLayout>
#include <QLabel>

GroupNotSelectedView::GroupNotSelectedView(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *rootLayout = new QVBoxLayout;
    QLabel *msgLabel = new QLabel("Выберите группу для просмотра.");
    rootLayout->addWidget(msgLabel);
    setLayout(rootLayout);
}
