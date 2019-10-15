#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
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
    query.prepare("SELECT gr.id, gr.name, 0 as word_count FROM " GROUPS_TABLE);

    if (query.exec()) {
        while (query.next()) {
            Group* gr = new Group;
            gr->setId(query.value(0).toInt());
            gr->setName(query.value(1).toString());
            gr->setWordCount(query.value(2).toInt());

            groupList << gr;
        }
    }

    return groupList;
}

Group *DbManager::insertGroup(const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " GROUPS_TABLE " (name) VALUES ((:name))");
    query.bindValue(":name", name);

    qDebug() << QString("insert here %1").arg(name);

    if (query.exec()) {
        qDebug() << "insert done";
        Group* group = new Group;
        group->setId(query.lastInsertId().toInt());
        group->setName(name);

        return group;
    }

    return nullptr;
}

Group *DbManager::getGroupById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM " GROUPS_TABLE " WHERE id=(:id)");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            Group* group = new Group;
            group->setId(query.value(0).toInt());
            group->setName(query.value(1).toString());

            return group;
        }
    }

    return nullptr;
}

Group *DbManager::getOrInsertGroup(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM " GROUPS_TABLE " WHERE name=(:name)");
    query.bindValue(":name", name);

    if (query.exec()) {
        if (query.next()) {
            Group* group = new Group;
            group->setId(query.value(0).toInt());
            group->setName(name);

            return group;
        } else {
            Group *group = insertGroup(name);
            return group;
        }
    }

    return nullptr;
}

Group *DbManager::saveGroup(Group *gr)
{
    QSqlQuery query;
    query.prepare("SELECT 1 FROM " GROUPS_TABLE " WHERE id=:id");
    query.bindValue(":id", gr->getId());

    qDebug() << QString("Saving group(%1, %2)").arg(QString::number(gr->getId()), gr->getName());

    if (query.exec()) {
        if (query.next()) {
            qDebug() << "Group already exists, updating...";
            query.prepare("UPDATE " GROUPS_TABLE " SET name=(:name) WHERE id=:id");
            query.bindValue(":id", gr->getId());
            query.bindValue(":name", gr->getName());            

            if (query.exec()) {
                qDebug() << "Group updated.";
                return gr;
            }
        } else {
            qDebug() << "Inserting new group.";
            return insertGroup(gr->getName());
        }
    } else {
        qDebug() << query.lastError().text();
    }

    return nullptr;
}

Translation *DbManager::getTranslationById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM " TRANSLATIONS_TABLE " WHERE id=(:id)");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            Translation* tr = new Translation;
            tr->setId(query.value(0).toInt());
            //tr->setName(query.value(1).toString());

            return tr;
        }
    }

    return nullptr;
}
