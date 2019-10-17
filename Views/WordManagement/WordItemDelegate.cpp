#include <QLineEdit>
#include <QStylePainter>
#include <QApplication>

#include <Views/WordManagement/WordItemDelegate.h>
#include <Views/WordManagement/TranslationEditor.h>

WordModel::WordRoles WordItemDelegate::getWordRoleByColumn(int column) const
{
    switch (column) {
    case 0: return WordModel::TextRole;
    case 1: return WordModel::TranscriptionRole;
    case 2: return WordModel::IdRole;
    }

    return WordModel::TextRole;
}

WordItemDelegate::WordItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *WordItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2) {
        int groupid = index.data(WordModel::GroupIdRole).toInt();
        int wordid = index.data(WordModel::IdRole).toInt();
        TranslationEditor *editor = new TranslationEditor(groupid, wordid, parent);
        return editor;
    } else {
        QLineEdit *editor = new QLineEdit(parent);
        editor->setFrame(false);

        return editor;
    }
}

void WordItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 2) {

    } else {
        QString value = index.data(getWordRoleByColumn(index.column())).toString();

        QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
        nameEdit->setText(value);
    }

}

void WordItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 2) {

    } else {
        QLineEdit *nameEdit = static_cast<QLineEdit*>(editor);
        QString text = nameEdit->text();

        model->setData(index, text, getWordRoleByColumn(index.column()));
    }
}

void WordItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2) {
        QPoint pos = option.widget->mapToGlobal(QPoint(option.rect.x(), option.rect.y()));
        editor->setGeometry(pos.x() + 2, pos.y() + 18, option.rect.width(), 200);
    } else {
        editor->setGeometry(option.rect);
    }
}

QSize WordItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(QStyledItemDelegate::sizeHint(option, index).width(), 48);
}

void WordItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    QFont font = painter->font();
    font.setPointSize(16);

    if (index.column() == 0) {
        QString zh = index.data(WordModel::TextRole).toString();
        painter->setFont(font);
        painter->drawText(option.rect.x() + 10, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, zh);
    } else if (index.column() == 1) {
        QString transcription = index.data(WordModel::TranscriptionRole).toString();
        font.setPointSize(10);
        font.setBold(false);
        painter->setFont(font);
        painter->drawText(option.rect.x() + 10, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, transcription);
    } else if (index.column() == 2) {
        QString translations = index.data(WordModel::TranslationsRole).toString();
        font.setPointSize(10);
        font.setBold(false);
        painter->setFont(font);
        painter->drawText(option.rect.x() + 10, option.rect.y(), option.rect.width() - 10, option.rect.height(), Qt::AlignLeft, translations);
    }
}


