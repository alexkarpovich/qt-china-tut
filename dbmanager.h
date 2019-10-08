#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include "models/group.h"

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    bool openConnection();
    static QList<Group*> getAllGroups();
};

#endif // DBMANAGER_H
