#include <QDebug>
#include <Models/TranslationModel.h>
#include <dbmanager.h>

TranslationModel::TranslationModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

QVariant TranslationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const GroupTranslation* tr = translations[index.row()];

//    switch (role) {
//    case IdRole: return wrd->getId();
//    case GroupIdRole: return wrd->getGroupId();
//    case ZhRole: return wrd->getZh();
//    case RuRole: return wrd->getRu();
//    case TranscriptionRole: return wrd->getTranscription();
//    }

    return QVariant();
}

int TranslationModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return translations.size();
}

Qt::ItemFlags TranslationModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool TranslationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) {
        GroupTranslation *tr = translations.at(index.row());

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

QVariant TranslationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};
    switch (section) {
    case 0: return "Слово";
    case 1: return "Транскрипция";
    case 2: return "Перевод";
    default: return {};
    }
}

void TranslationModel::addTranslation(GroupTranslation* tr)
{
    beginResetModel();

    translations << tr;

    endResetModel();
}

void TranslationModel::setTranslations(QList<GroupTranslation *> _trl)
{
    beginResetModel();
    translations = _trl;
    endResetModel();
}

QHash<int, QByteArray> TranslationModel::roleNames() const
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

int TranslationModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}
