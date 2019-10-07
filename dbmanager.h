#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DbManager
{
    QSqlDatabase m_db;
public:
    DbManager(const QString& path);
    bool openConnection();
};

#endif // DBMANAGER_H
