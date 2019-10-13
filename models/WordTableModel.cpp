#include <QDebug>
#include "WordTableModel.h"
#include <dbmanager.h>

WordTableModel::WordTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

QVariant WordTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const Word* wrd = words[index.row()];

    switch (role) {
    case IdRole: return wrd->getId();
    case GroupIdRole: return wrd->getGroupId();
    case ZhRole: return wrd->getZh();
    case RuRole: return wrd->getRu();
    case TranscriptionRole: return wrd->getTranscription();
    }

    return QVariant();
}

int WordTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return words.size();
}

Qt::ItemFlags WordTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool WordTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) {
        Word *wrd = words.at(index.row());

        switch (role) {
        case ZhRole: wrd->setZh(value.toString()); break;
        case RuRole: wrd->setRu(value.toString()); break;
        case TranscriptionRole: wrd->setTranscription(value.toString()); break;
        }
        wrd = DbManager::saveGroupWord(wrd->getGroupId(), wrd);
        words.replace(index.row(), wrd);
        emit dataChanged(index, index);
        return true;

     }

    return false;
}

QVariant WordTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};
    switch (section) {
    case 0: return "Слово";
    case 1: return "Транскрипция";
    case 2: return "Перевод";
    default: return {};
    }
}

void WordTableModel::addWord(Word* wrd)
{
    beginResetModel();

    words << wrd;

    endResetModel();
}

void WordTableModel::setWords(QList<Word *> _words)
{
    beginResetModel();
    words = _words;
    endResetModel();
}

QHash<int, QByteArray> WordTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[ZhRole] = "zh";
    roles[RuRole] = "ru";
    roles[TranscriptionRole] = "transcription";
    roles[StatusRole] = "status";
    roles[GroupIdRole] = "group id";

    return roles;
}

int WordTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}
