#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include <Dao/GroupDao.h>
#include <Dao/WordDao.h>
#include <Dao/ProfileDao.h>

GroupDao::GroupDao()
{
    ProfileDao pd;
    profile = pd.get(1);
}

QList<Group *> GroupDao::all()
{
    QList<Group *> groups;
    QSqlQuery query;
    query.prepare("SELECT id, name, 0 as word_count FROM" GROUP_TABLE
                  "WHERE lang_id=:langid");
    query.bindValue(":langid", profile->getLearningLang()->getId());

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
    query.prepare("SELECT id, name, 0 as word_count FROM" GROUP_TABLE "WHERE id=:id");
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
    query.prepare("INSERT INTO" GROUP_TABLE "(name, lang_id) VALUES ((:name), :langid)");
    query.bindValue(":name", value->getName());
    query.bindValue(":langid", profile->getLearningLang()->getId());

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

    if (query.exec()) {
        qDebug() << QString("Group was updated (%1, %2)").arg(QString::number(value->getId()), value->getName());
    } else {
        qDebug() << QString("Group update error: %1").arg(query.lastError().text());
    }
}

void GroupDao::del(Group *value)
{
    QSqlQuery query;
    query.prepare("DELETE FROM" GROUP_TABLE "WHERE id=:id");
    query.bindValue(":id", value->getId());

    if (query.exec()) {
        qDebug() << QString("Group (%1, %2) was deleted").arg(QString::number(value->getId()), value->getName());
    } else {
        qDebug() << QString("Group deleting error: %1").arg(query.lastError().text());
    }
}

Word *GroupDao::addWord(int groupid, const QString &text)
{
    WordDao wd;
    Word *wrd = wd.getByText(text);

    if (!wrd) {
        wrd = new Word;
        wrd->setText(text);
        wrd = wd.create(wrd);
    }

    QSqlQuery query;
    query.prepare("INSERT INTO groups_words (group_id, word_id) VALUES (:groupid, :wordid) ON DUPLICATE KEY IGNORE");
    query.bindValue(":groupid", groupid);
    query.bindValue(":wordid", wrd->getId());

    if (query.exec()) {
        return wrd;
    } else {
        qDebug() << QString("Group deleting error: %1").arg(query.lastError().text());
    }
}
