#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <Entities/Group.h>
#include <Entities/Word.h>

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    bool openConnection();
    static QList<Group*> getAllGroups();
    static QList<Word *> getAllGroupWords(int groupId);
    static Word *insertWord(const QString& zh, const QString& ru, const QString& transcription, int status);
    static Group *insertGroup(const QString& name);
    static Word *insertGroupWord(int groupId, const QString &zh);
    static Group* getOrInsertGroup(const QString& name);
    static Word *getOrInsertWord(const QString& zh);
    static Group *saveGroup(Group *gr);
    static Word *saveGroupWord(int groupId, Word *wrd);
    static bool groupWordExists(int groupId, Word *wrd);
};

#endif // DBMANAGER_H
