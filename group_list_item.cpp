#include <models/group_list_model.h>
#include <QLineEdit>
#include <QStylePainter>
#include <QApplication>
#include "group_list_item.h"

GroupListItem::GroupListItem(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *GroupListItem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    return editor;
}

void GroupListItem::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.data(GroupListModel::NameRole).toString();

    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    nameEdit->setText(value);
}

void GroupListItem::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    QString groupName = nameEdit->text();

    model->setData(index, groupName, GroupListModel::NameRole);
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
    QString name = index.data(GroupListModel::NameRole).toString();
    int wordCount = index.data(GroupListModel::WordCountRole).toInt();

    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }
    QFont font = painter->font();
    font.setPointSize(10);
    font.setBold(true);
    painter->setFont(font);

    painter->drawText(option.rect.left() + 10, option.rect.top() + 20, name);

    font.setPointSize(8);
    font.setBold(false);
    painter->setFont(font);
    painter->drawText(option.rect.left() + 10, option.rect.top() + 40, QString("%1 word(s)").arg(wordCount));
}


