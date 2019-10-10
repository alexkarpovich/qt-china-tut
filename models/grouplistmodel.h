#ifndef GROUPLISTMODEL_H
#define GROUPLISTMODEL_H

#include <QList>
#include <QHash>
#include <QVariant>
#include <QModelIndex>
#include <QAbstractListModel>
#include <entities/group.h>


class GroupListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Group*> groups;
public:
    explicit GroupListModel(QObject *parent = nullptr);

    enum groupRoles {
        NameRole = Qt::DisplayRole,
        IdRole = Qt::UserRole + 1
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
              int role = Qt::EditRole);
public slots:
    void addGroup(Group* gr);
private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // GROUPLISTMODEL_H
