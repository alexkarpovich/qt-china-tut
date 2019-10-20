#include "LearningView.h"

#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

#include <Views/Cards/Card.h>

LearningView::LearningView(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * rootLayout = new QVBoxLayout;

    Card *card = new Card;
    rootLayout->addWidget(card, 1, Qt::AlignHCenter);

    setLayout(rootLayout);
}
