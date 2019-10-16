#include "TranslationModel.h"

TranslationModel::TranslationModel(int wordid, QObject *parent)
    : QAbstractListModel(parent)
{
    this->wordid = wordid;
    wordDao = new WordDao;
    options = wordDao->translations(wordid);
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

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool TranslationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) {
        emit dataChanged(index, index);
        return true;

     }

    return false;
}

void TranslationModel::addTranslation(const QString &text)
{
    Word *wrd = wordDao->addTranslation(wordid, text);
    options << wrd;
}

QHash<int, QByteArray> TranslationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[TextRole] = "text";

    return roles;
}
