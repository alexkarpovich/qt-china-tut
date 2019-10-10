#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QStyleOptionViewItemV4>
#include <models/grouplistmodel.h>
#include <models/grouplistmodel.h>
#include "grouplistitem.h"

GroupListItem::GroupListItem()
{

}

GroupListItem::~GroupListItem()
{
}

//alocate each item size in listview.
QSize GroupListItem::sizeHint(const QStyleOptionViewItem &  option ,
                              const QModelIndex & index) const
{
//    QIcon icon = qvariant_cast<QIcon>(index.data(IconRole));
//    QSize iconsize = icon.actualSize(option.decorationSize);
//    QFont font = QApplication::font();
//    QFontMetrics fm(font);

    return(QSize(24, 24));

}
void GroupListItem::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{

    if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());
        QWidget *widget = new QPushButton("bonjour");
        widget->render(painter, QPoint(option.rect.x() + 20, option.rect.y() + 3), QRegion(option.rect));
}
