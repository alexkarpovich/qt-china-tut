#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <Entities/Group.h>
#include <Entities/Translation.h>
#include <Entities/GroupTranslation.h>

#define GROUPS_TABLE "groups"
#define GROUP_TRANSLATION_TABLE "group_translation"
#define TRANSLATIONS_TABLE "translations"
#define ZH_TABLE "zh"
#define RU_TABLE "ru"

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    bool openConnection();
    static QList<Group*> getAllGroups();
    static QList<GroupTranslation *> getAllGroupTranslations();
    static Group *insertGroup(const QString& name);
    static Group *getGroupById(int id);
    static Group* getOrInsertGroup(const QString& name);
    static Group *saveGroup(Group *gr);
    static Language *getSourceByDirAndId(Translation::Direction dir, int id);
    static Translation *getTranslationById(int id);
};

#endif // DBMANAGER_H
