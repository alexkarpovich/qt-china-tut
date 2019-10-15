#include <QLineEdit>
#include <QStylePainter>
#include <QApplication>

#include <Views/WordManagement/WordItemDelegate.h>

WordModel::WordRoles WordItemDelegate::getWordRoleByColumn(int column) const
{
    switch (column) {
    case 0: return WordModel::ZhRole;
    case 1: return WordModel::TranscriptionRole;
    case 2: return WordModel::RuRole;
    }

    return WordModel::ZhRole;
}

WordItemDelegate::WordItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *WordItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    return editor;
}

void WordItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.data(getWordRoleByColumn(index.column())).toString();

    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    nameEdit->setText(value);
}

void WordItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
    QString text = nameEdit->text();

    model->setData(index, text, getWordRoleByColumn(index.column()));
}

void WordItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

QSize WordItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(QStyledItemDelegate::sizeHint(option, index).width(), 48);
}

void WordItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString zh = index.data(WordModel::ZhRole).toString();
    QString ru = index.data(WordModel::RuRole).toString();
    QString transcription = index.data(WordModel::TranscriptionRole).toString();

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


