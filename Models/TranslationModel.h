#ifndef TRANSLATIONMODEL_H
#define TRANSLATIONMODEL_H

#include <QAbstractListModel>
#include <Entities/Word.h>
#include <Dao/WordDao.h>

class TranslationModel : public QAbstractListModel
{
    int groupid;
    int wordid;
    QList<Word *> options;
    WordDao *wordDao;
public:
    enum TranslationRole {
        IdRole = Qt::UserRole,
        TextRole = Qt::UserRole + 1
    };
    explicit TranslationModel(int groupid, int wordid, QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
              int role = Qt::EditRole);
public slots:
    void addTranslation(const QString& text);
private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // TRANSLATIONMODEL_H
