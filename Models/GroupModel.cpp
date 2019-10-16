#include "GroupModel.h"

GroupModel::GroupModel(QObject *parent)
    : QAbstractListModel(parent)
{
    groupDao = new GroupDao;
    groups = groupDao->all();
}

QVariant GroupModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > groups.count()) {
        return QVariant();
    }

    const Group* gr = groups[index.row()];

    switch (role) {
    case IdRole: return gr->getId();
    case NameRole: return gr->getName();
    case WordCountRole: return gr->getWordCount();
    }

    return QVariant();
}

int GroupModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return groups.size();
}

Qt::ItemFlags GroupModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool GroupModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == NameRole) {
        GroupDao gd;
        Group *gr = groups.at(index.row());
        gr->setName(value.toString());
        gd.update(gr);
        groups.replace(index.row(), gr);
        emit dataChanged(index, index);
        return true;

     }

     return false;
}

void GroupModel::addGroup(const QString& name)
{
    beginResetModel();
    Group * gr = groupDao->create(name);
    groups << gr;
    endResetModel();
}

QHash<int, QByteArray> GroupModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[IdRole] = "id";
    roles[WordCountRole] = "word count";

    return roles;
}
