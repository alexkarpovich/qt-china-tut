#include "wordlistitem.h"
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
    WordListItem* wlItem = new WordListItem;
    wlItem->setWordText(text);

    QListWidgetItem* item = new QListWidgetItem( this );
    item->setSizeHint( wlItem->sizeHint() );
    setItemWidget( item, wlItem );
}
