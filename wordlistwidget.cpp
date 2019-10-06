#include "wordlistwidget.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <qlabel.h>

WordListWidget::WordListWidget(QWidget* parent)
    : QListWidget(parent)
{

}

void WordListWidget::appendWord(const QString text)
{
    QWidget* wgt = new QWidget;
    QLayout* l = new QHBoxLayout;
    QLabel* wordLbl = new QLabel(text);
    QFont font = wordLbl->font();
    font.setPointSize(24);
    wordLbl->setFont(font);
    l->setMargin(3);

    l->addWidget( wordLbl );
    QWidget* actionsWgt = new QWidget;
    QVBoxLayout* actionsLayout = new QVBoxLayout;
    actionsLayout->setMargin(0);
    QPushButton* editBtn = new QPushButton("✎");
    editBtn->setStyleSheet("margin: 0;background-color:#ada11a;");
    editBtn->setFixedSize(24, 24);
    QPushButton* removeBtn = new QPushButton("✕");
    removeBtn->setStyleSheet("margin: 0;background-color:#ad1a1a;");
    removeBtn->setFixedSize(24, 24);
    //connect( btn, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
    actionsLayout->addWidget( editBtn );
    actionsLayout->addWidget(removeBtn);
    actionsWgt->setLayout(actionsLayout);
    actionsWgt->setMaximumWidth(24);
    l->addWidget(actionsWgt);
    wgt->setLayout( l );

    QListWidgetItem* item = new QListWidgetItem( this );
    item->setSizeHint( wgt->sizeHint() );
    setItemWidget( item, wgt );
}
