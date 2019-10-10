#include <models/grouplistmodel.h>
#include <QPushButton>
#include <QSpinBox>
#include <QStylePainter>
#include <QApplication>
#include "grouplistitem.h"

GroupListItem::GroupListItem(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *GroupListItem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(0);
    editor->setMaximum(100);

    return editor;
}

void GroupListItem::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.data(GroupListModel::IdRole).toInt();

    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void GroupListItem::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, GroupListModel::IdRole);
}

void GroupListItem::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

QSize GroupListItem::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(QStyledItemDelegate::sizeHint(option, index).width(), 48);
}

void GroupListItem::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }
    QFont font = painter->font();
    font.setPointSize(10);
    font.setBold(true);
    painter->setFont(font);

    painter->drawText(option.rect.left() + 10, option.rect.top() + 20, index.data().toString());

    font.setPointSize(8);
    font.setBold(false);
    painter->setFont(font);
    painter->drawText(option.rect.left() + 10, option.rect.top() + 40, "10 items");
}


