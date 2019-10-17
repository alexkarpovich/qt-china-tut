#include "TranslationItemDelegate.h"
#include <Models/TranslationModel.h>

TranslationItemDelegate::TranslationItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void TranslationItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }


    QFont font = painter->font();
    font.setPointSize(10);

    QString text = index.data(TranslationModel::TextRole).toString();

    painter->setFont(font);
    painter->drawText(option.rect.x() + 10, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, text);
}
