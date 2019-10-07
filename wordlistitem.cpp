#include "wordlistitem.h"

#include <QHBoxLayout>

WordListItem::WordListItem(QWidget *parent) : QWidget(parent)
{
    QLayout* l = new QHBoxLayout;
    wordLabel = new QLabel;
    QFont font = wordLabel->font();
    font.setPointSize(24);
    wordLabel->setFont(font);
    l->setMargin(3);

    l->addWidget( wordLabel );
    QWidget* actionsWgt = new QWidget;
    QVBoxLayout* actionsLayout = new QVBoxLayout;
    actionsLayout->setMargin(0);
    editButton = new QPushButton("✎");
    editButton->setStyleSheet("margin: 0;background-color:#ada11a;");
    editButton->setFixedSize(24, 24);
    removeButton = new QPushButton("✕");
    removeButton->setStyleSheet("margin: 0;background-color:#ad1a1a;");
    removeButton->setFixedSize(24, 24);
    //connect( btn, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
    actionsLayout->addWidget(editButton);
    actionsLayout->addWidget(removeButton);
    actionsWgt->setLayout(actionsLayout);
    actionsWgt->setMaximumWidth(24);
    l->addWidget(actionsWgt);
    setStyleSheet("border-bottom: 1px solid black;");
    setLayout( l );
}

void WordListItem::setWordText(const QString text)
{
    wordLabel->setText(text);
}
