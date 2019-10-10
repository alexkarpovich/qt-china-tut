#include "grouplistmodel.h"

GroupListModel::GroupListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

QVariant GroupListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > groups.count()) {
        return QVariant();
    }

    const Group* gr = groups[index.row()];

    if (role == NameRole)
        return gr->getName();
    else if (role == IdRole)
        return gr->getId();
    return QVariant();
}

int GroupListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return groups.size();
}

void GroupListModel::addGroup(Group *gr)
{
    beginResetModel();

    groups << gr;

    endResetModel();
}

QHash<int, QByteArray> GroupListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[IdRole] = "id";

    return roles;
}
