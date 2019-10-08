#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include "models/group.h"
#include "models/groupword.h"
#include "models/wort.h"

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    bool openConnection();
    static QList<Group*> getAllGroups();
    static Wort *insertWord(const QString& zh, const QString& ru, const QString& transcription, int status);
    static Group *insertGroup(const QString& name);
    static Group* getOrInsertGroup(const QString& name);
    static Wort *getOrInsertWord(const QString& zh);
    static GroupWord *addGroupWord(const QString& text);
};

#endif // DBMANAGER_H
