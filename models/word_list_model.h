#ifndef WORDLISTMODEL_H
#define WORDLISTMODEL_H

#include <QList>
#include <QHash>
#include <QVariant>
#include <QModelIndex>
#include <QAbstractListModel>
#include <entities/word.h>


class WordListModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Word*> words;
public:
    explicit WordListModel(QObject *parent = nullptr);

    enum wordRoles {
        ZhRole = Qt::DisplayRole,
        IdRole = Qt::UserRole + 1,
        RuRole = Qt::UserRole + 2,
        TranscriptionRole = Qt::UserRole + 3,
        StatusRole = Qt::UserRole + 4,
        GroupIdRole = Qt::UserRole + 5
    };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
              int role = Qt::EditRole);
public slots:
    void addWord(Word* wrd);
    void setWords(QList<Word*> _words);
private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // WORDLISTMODEL_H
