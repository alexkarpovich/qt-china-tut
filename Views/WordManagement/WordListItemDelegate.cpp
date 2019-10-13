#include <QLineEdit>
#include <QStylePainter>
#include <QApplication>

#include <Views/WordManagement/WordListItemDelegate.h>

WordTableModel::WordRoles WordListItemDelegate::getWordRoleByColumn(int column) const
{
    switch (column) {
    case 0: return WordTableModel::ZhRole;
    case 1: return WordTableModel::TranscriptionRole;
    case 2: return WordTableModel::RuRole;
    }

    return WordTableModel::ZhRole;
}

WordListItemDelegate::WordListItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *WordListItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    return editor;
}

void WordListItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.data(getWordRoleByColumn(index.column())).toString();

    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    nameEdit->setText(value);
}

void WordListItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    QString text = nameEdit->text();

    model->setData(index, text, getWordRoleByColumn(index.column()));
}

void WordListItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

QSize WordListItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(QStyledItemDelegate::sizeHint(option, index).width(), 48);
}

void WordListItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString zh = index.data(WordTableModel::ZhRole).toString();
    QString ru = index.data(WordTableModel::RuRole).toString();
    QString transcription = index.data(WordTableModel::TranscriptionRole).toString();

    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }
    QFont font = painter->font();
    font.setPointSize(18);

    if (index.column() == 0) {
        painter->setFont(font);
        painter->drawText(option.rect.x() + 10, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, zh);
    } else if (index.column() == 1) {
        font.setPointSize(8);
        font.setBold(false);
        painter->setFont(font);
        painter->drawText(option.rect.x() + 10, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, transcription);
    } else if (index.column() == 2) {
        font.setPointSize(8);
        font.setBold(false);
        painter->setFont(font);
        painter->drawText(option.rect.x() + 10, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, ru);
    }
}


