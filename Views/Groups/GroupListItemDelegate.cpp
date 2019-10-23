#include <QLineEdit>
#include <QStylePainter>
#include <QApplication>

#include <Models/GroupModel.h>
#include "GroupListItemDelegate.h"

GroupListItemDelegate::GroupListItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *GroupListItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    return editor;
}

void GroupListItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.data(GroupModel::NameRole).toString();

    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    nameEdit->setText(value);
}

void GroupListItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    QString groupName = nameEdit->text();

    model->setData(index, groupName, GroupModel::NameRole);
}

void GroupListItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

QSize GroupListItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(QStyledItemDelegate::sizeHint(option, index).width(), 48);
}

void GroupListItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString name = index.data(GroupModel::NameRole).toString();
    int wordCount = index.data(GroupModel::WordCountRole).toInt();

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


