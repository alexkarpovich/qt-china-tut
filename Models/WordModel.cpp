#include <QDebug>
#include <Models/WordModel.h>
#include <Dao/GroupDao.h>
#include <Dao/WordDao.h>

WordModel::WordModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

QVariant WordModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const Word* wrd = words[index.row()];

//    switch (role) {
//    case IdRole: return wrd->getId();
//    case GroupIdRole: return wrd->getGroupId();
//    case ZhRole: return wrd->getZh();
//    case RuRole: return wrd->getRu();
//    case TranscriptionRole: return wrd->getTranscription();
//    }

    return QVariant();
}

int WordModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return words.size();
}

Qt::ItemFlags WordModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool WordModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) {
        Word *wrd = words.at(index.row());

//        switch (role) {
//        case ZhRole: tr->setZh(value.toString()); break;
//        case RuRole: tr->setRu(value.toString()); break;
//        case TranscriptionRole: tr->setTranscription(value.toString()); break;
//        }
//        tr = DbManager::saveGroupWord(tr->getGroupId(), tr);
//        translations.replace(index.row(), tr);
        emit dataChanged(index, index);
        return true;

     }

    return false;
}

QVariant WordModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};
    switch (section) {
    case 0: return "Слово";
    case 1: return "Транскрипция";
    case 2: return "Перевод";
    default: return {};
    }
}

void WordModel::addWord(const QString &value)
{
    beginResetModel();
    GroupDao gd;
    WordDao wd;
    Word *wrd = gd.addWord(1, value);
    words << wrd;
    QList<Word *> translations = wd.translations(wrd->getId());
    options[wrd->getId()] = translations;
    endResetModel();
}

void WordModel::setWords(QList<Word *> list)
{
    beginResetModel();
    words = list;
    endResetModel();
}

QHash<int, QByteArray> WordModel::roleNames() const
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

int WordModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}
