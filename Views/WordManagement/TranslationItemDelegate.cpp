#include <Application.h>
#include "TranslationItemDelegate.h"
#include <Models/TranslationModel.h>

TranslationItemDelegate::TranslationItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

bool TranslationItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{

    if (event->type() == QEvent::MouseButtonRelease) {
        bool isSelected = index.data(TranslationModel::IsSelectedRole).toBool();
        model->setData(index, !isSelected, TranslationModel::IsSelectedRole);
    }

    return false;
}

void TranslationItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    QString text = index.data(TranslationModel::TextRole).toString();
    bool isSelected = index.data(TranslationModel::IsSelectedRole).toBool();

    QFont font = painter->font();
    font.setPointSize(10);   

    QStyleOptionButton check_box;
    check_box.state = QStyle::State_Enabled;
    check_box.rect = option.rect;
    check_box.state |= isSelected ? QStyle::State_On : QStyle::State_Off;
    Application::style()->drawControl(QStyle::CE_CheckBox, &check_box, painter);

    painter->setFont(font);
    painter->drawText(option.rect.x() + 20, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, text);

}
