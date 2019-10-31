#ifndef WORDMODEL_H
#define WORDMODEL_H

#include <QList>
#include <QHash>
#include <QVariant>
#include <QModelIndex>
#include <QAbstractTableModel>

#include <Entities/Word.h>
#include <Dao/GroupDao.h>
#include <Dao/WordDao.h>


class WordModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<int> groupids;
    QList<Word*> words;
    QMap<int, QList<Word *>> options;
    QMap<int, bool> optionFlags;
    QMap<int, QString> formattedOptions;
    WordDao *wordDao;
    GroupDao *groupDao;

public:
    explicit WordModel(QList<int> groupids, QObject *parent = nullptr);

    enum WordRoles {
        IdRole = Qt::UserRole,
        TextRole = Qt::UserRole + 1,
        TranscriptionRole = Qt::UserRole + 2,
        TranslationsRole = Qt::UserRole + 3,
        GroupIdsRole = Qt::UserRole + 4
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
    void addWord(const QString& value);
private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // WORDMODEL_H
