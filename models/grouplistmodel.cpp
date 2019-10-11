#include "grouplistmodel.h"

#include <dbmanager.h>

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

Qt::ItemFlags GroupListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool GroupListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == NameRole) {

        Group *gr = groups.at(index.row());
        gr->setName(value.toString());
        gr = DbManager::updateOrInsertGroup(gr);
        groups.replace(index.row(), gr);
        emit dataChanged(index, index);
        return true;

     }

     return false;
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
    roles[WordCountRole] = "word count";

    return roles;
}
