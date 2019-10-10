#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include "entities/group.h"
#include "entities/groupword.h"
#include "entities/word.h"

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    bool openConnection();
    static QList<Group*> getAllGroups();
    static Word *insertWord(const QString& zh, const QString& ru, const QString& transcription, int status);
    static Group *insertGroup(const QString& name);
    static Group* getOrInsertGroup(const QString& name);
    static Word *getOrInsertWord(const QString& zh);
    static GroupWord *addGroupWord(int groupId, const QString& text);
};

#endif // DBMANAGER_H
