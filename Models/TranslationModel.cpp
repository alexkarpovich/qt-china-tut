#include <QDebug>
#include "TranslationModel.h"

TranslationModel::TranslationModel(QList<int> groupids, int wordid, QObject *parent)
    : QAbstractListModel(parent)
{
    this->groupids = groupids;
    this->wordid = wordid;
    wordDao = new WordDao;
    options = wordDao->translations(wordid);
    optionFlags = wordDao->translationFlags(groupids, wordid);
    qDebug() << options.size();
}

QVariant TranslationModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > options.count()) {
        return QVariant();
    }

    const Word* wrd = options[index.row()];

    switch (role) {
    case IdRole: return wrd->getId();
    case TextRole: return wrd->getText();
    case IsSelectedRole: return optionFlags.contains(wrd->getId()) && optionFlags[wrd->getId()];
    }

    return QVariant();
}

int TranslationModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return options.size();
}

Qt::ItemFlags TranslationModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsUserCheckable;
}

bool TranslationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) {
        Word *wrd = options[index.row()];

        if (role == IsSelectedRole) {
            optionFlags[wrd->getId()] = value.toBool();
        }
        wordDao->updateTranslationFlags(groupid, wordid, wrd->getId(), value.toBool());
        emit dataChanged(index, index);
        return true;

     }

    return false;
}

void TranslationModel::addTranslation(const QString &text)
{
    Word *wrd = wordDao->addTranslation(groupid, wordid, text);
    options << wrd;
}

QHash<int, QByteArray> TranslationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[TextRole] = "text";

    return roles;
}
