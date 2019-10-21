#include <QDebug>
#include <QVariant>
#include <Models/WordModel.h>

WordModel::WordModel(QList<int> groupids, QObject *parent)
    : QAbstractTableModel(parent), groupids(groupids)
{
    wordDao = new WordDao;
    groupDao = new GroupDao;
    words = groupDao->words(groupids);
}

QVariant WordModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const Word* wrd = words[index.row()];

    switch (role) {
    case IdRole: return wrd->getId();
    case TextRole: return wrd->getText();
    case TranscriptionRole: return wrd->getTranscription();
    case TranslationsRole: return "TRANSLATIONS";
    case GroupIdsRole: return QVariant::fromValue(groupids);
    }

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

        if (role == TranscriptionRole) {
            wrd->setTranscription(value.toString());
            wordDao->update(wrd);
            words.replace(index.row(), wrd);
        }

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
    Word *wrd = gd.addWord(groupids, value);
    words << wrd;
    QList<Word *> translations = wd.translations(wrd->getId());
    options[wrd->getId()] = translations;
    endResetModel();
}


QHash<int, QByteArray> WordModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[TextRole] = "text";
    roles[TranscriptionRole] = "transcription";

    return roles;
}

int WordModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}
