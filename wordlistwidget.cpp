#include "wordlistwidget.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

WordListWidget::WordListWidget(QWidget* parent)
    : QListWidget(parent)
{

}

void WordListWidget::appendWord(const QString text)
{
    QWidget* wgt = new QWidget;
    QLayout* l = new QHBoxLayout;
    l->setMargin(3);
    l->addWidget( new QLineEdit(text) );
    QPushButton* btn = new QPushButton( "Click me" );
    connect( btn, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
    l->addWidget( btn );
    wgt->setLayout( l );

    QListWidgetItem* item = new QListWidgetItem( this );
    item->setSizeHint( wgt->sizeHint() );
    setItemWidget( item, wgt );
}
