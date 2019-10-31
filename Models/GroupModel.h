#ifndef GROUPMODEL_H
#define GROUPMODEL_H

#include <QList>
#include <QHash>
#include <QVariant>
#include <QModelIndex>
#include <QAbstractListModel>

#include <Entities/Group.h>
#include <Dao/GroupDao.h>


class GroupModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Group*> groups;
    GroupDao *groupDao;
public:
    explicit GroupModel(QObject *parent = nullptr);

    enum groupRoles {
        NameRole = Qt::DisplayRole,
        IdRole = Qt::UserRole + 1,
        WordCountRole = Qt::UserRole + 2
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
              int role = Qt::EditRole);
public slots:
    void addGroup(const QString& name);
    void increaseWordCount(int groupid);
private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // GROUPMODEL_H
