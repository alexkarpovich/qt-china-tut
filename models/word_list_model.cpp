#include "word_list_model.h"
#include <dbmanager.h>

WordListModel::WordListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

QVariant WordListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > words.count()) {
        return QVariant();
    }

    const Word* wrd = words[index.row()];

    if (role == IdRole) {
        return wrd->getId();
    } else if (role == ZhRole) {
        return wrd->getZh();
    } else if (role == RuRole) {
        return wrd->getRu();
    } else if (role == TranscriptionRole) {
        return wrd->getTranscription();
    } else if (role == StatusRole) {
        return wrd->getStatus();
    } else if (role == GroupIdRole) {
        return wrd->getGroupId();
    }

    return QVariant();
}

int WordListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return words.size();
}

Qt::ItemFlags WordListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool WordListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == ZhRole) {
        Word *wrd = words.at(index.row());
        wrd->setZh(value.toString());
        //gr = DbManager::updateOrInsertGroup(gr);
        words.replace(index.row(), wrd);
        emit dataChanged(index, index);
        return true;

     }

     return false;
}

void WordListModel::addWord(Word* wrd)
{
    beginResetModel();

    words << wrd;

    endResetModel();
}

void WordListModel::setWords(QList<Word *> _words)
{
    beginResetModel();
    words = _words;
    endResetModel();
}

QHash<int, QByteArray> WordListModel::roleNames() const
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
