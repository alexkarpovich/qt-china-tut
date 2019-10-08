#include "dbmanager.h"
#include <QSqlQuery>
#include <QDebug>

DbManager::DbManager(const QString& path)
{
    qDebug()  <<  QSqlDatabase::drivers();
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
}

bool DbManager::openConnection()
{
    return m_db.open();
}

QList<Group*> DbManager::getAllGroups()
{
    QSqlQuery query;
    QList<Group*> groupList;
    query.prepare("SELECT * FROM groups");

    while (query.next()) {
        Group* gr = new Group;
        gr->setId(query.value(0).toInt());
        gr->setName(query.value(1).toString());
    }

    return groupList;
}
