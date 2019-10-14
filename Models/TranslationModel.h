#ifndef TRANSLATIONMODEL_H
#define TRANSLATIONMODEL_H

#include <QList>
#include <QHash>
#include <QVariant>
#include <QModelIndex>
#include <QAbstractTableModel>
#include <Entities/GroupTranslation.h>


class TranslationModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<GroupTranslation*> translations;
public:
    explicit TranslationModel(QObject *parent = nullptr);

    enum TranslationRoles {
        IdRole = Qt::UserRole,
        ZhRole = Qt::UserRole + 1,
        RuRole = Qt::UserRole + 2,
        TranscriptionRole = Qt::UserRole + 3,
        StatusRole = Qt::UserRole + 4,
        GroupIdRole = Qt::UserRole + 5
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role = Qt::EditRole);
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
//    bool setHeaderData(int section,
//                       Qt::Orientation orientation,
//                       const QVariant &value,
//                       int role = Qt::EditRole);
public slots:
    void addTranslation(GroupTranslation* tr);
    void setTranslations(QList<GroupTranslation*> _trl);
private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // TRANSLATIONMODEL_H
