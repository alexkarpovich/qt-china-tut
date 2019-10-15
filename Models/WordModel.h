#ifndef WORDMODEL_H
#define WORDMODEL_H

#include <QList>
#include <QHash>
#include <QVariant>
#include <QModelIndex>
#include <QAbstractTableModel>
#include <Entities/Word.h>


class WordModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<Word*> words;
    QMap<int, QList<Word *>> options;
    QMap<int, bool> optionFlags;

public:
    explicit WordModel(QObject *parent = nullptr);

    enum WordRoles {
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
    void addWord(const QString& value);
    void setWords(QList<Word*> list);
private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // WORDMODEL_H
