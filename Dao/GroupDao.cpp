#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "GroupDao.h"

GroupDao::GroupDao()
{

}

QList<Group *> GroupDao::all()
{
    QList<Group *> groups;
    QSqlQuery query;
    query.prepare("SELECT gr.id, gr.name, 0 as word_count FROM" GROUP_TABLE);

    if (query.exec()) {
        while (query.next()) {
            Group* gr = new Group;
            gr->setId(query.value(0).toInt());
            gr->setName(query.value(1).toString());
            gr->setWordCount(query.value(2).toInt());

            groups << gr;
        }
    }

    return groups;
}

Group *GroupDao::get(int id)
{
    QSqlQuery query;
    query.prepare("SELECT gr.id, gr.name, 0 as word_count FROM" GROUP_TABLE "WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        Group* gr = new Group;
        gr->setId(query.value(0).toInt());
        gr->setName(query.value(1).toString());
        gr->setWordCount(query.value(2).toInt());

        return gr;
    }

    return nullptr;
}

Group *GroupDao::create(Group *value)
{
    QSqlQuery query;
    query.prepare("INSERT INTO" GROUP_TABLE "(name) VALUES ((:name))");
    query.bindValue(":name", value->getName());

    if (query.exec() && query.next()) {
        value->setId(query.lastInsertId().toInt());

        return value;
    }

    return nullptr;
}

void GroupDao::update(Group *value)
{
    QSqlQuery query;
    query.prepare("UPDATE" GROUP_TABLE "SET name=:name WHERE id=:id");
    query.bindValue(":id", value->getId());
    query.bindValue(":name", value->getName());

    if (query.exec() && query.next()) {
        qDebug() << QString("Group was updated (%1, %2)").arg(QString::number(value->getId()), value->getName());
    } else {
        qDebug() << QString("Group update error: %s").arg(query.lastError().text());
    }
}

void GroupDao::del(Group *value)
{
    QSqlQuery query;
    query.prepare("DELETE FROM" GROUP_TABLE "WHERE id=:id");
    query.bindValue(":id", value->getId());

    if (query.exec() && query.next()) {
        qDebug() << QString("Group (%1, %2) was deleted").arg(QString::number(value->getId()), value->getName());
    } else {
        qDebug() << QString("Group deleting error: %s").arg(query.lastError().text());
    }
}
