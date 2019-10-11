#include <models/word_list_model.h>
#include <QLineEdit>
#include <QStylePainter>
#include <QApplication>
#include "word_list_item.h"

WordListItem::WordListItem(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *WordListItem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    return editor;
}

void WordListItem::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.data(WordListModel::ZhRole).toString();

    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    nameEdit->setText(value);
}

void WordListItem::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    QString zh = nameEdit->text();

    model->setData(index, zh, WordListModel::ZhRole);
}

void WordListItem::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

QSize WordListItem::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(QStyledItemDelegate::sizeHint(option, index).width(), 48);
}

void WordListItem::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString zh = index.data(WordListModel::ZhRole).toString();
    QString ru = index.data(WordListModel::RuRole).toString();
    QString transcription = index.data(WordListModel::TranscriptionRole).toString();

    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    QFont font = painter->font();
    font.setPointSize(14);
    font.setBold(true);
    painter->setFont(font);
    QFontMetrics fm(font, painter->device());
    QRect zhRect = fm.boundingRect(zh);

    painter->drawText(option.rect.left() + 10, option.rect.top() + 20, zh);

    font.setPointSize(8);
    font.setBold(false);
    painter->setFont(font);
    painter->drawText(zhRect.right() + 20, option.rect.top() + 20, transcription);
    painter->drawText(zhRect.right() + 20, option.rect.top() + 40, ru);
}


