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
    query.prepare("SELECT gr.id, gr.name, COUNT(gw.word_id) as word_count FROM groups gr "\
                  "LEFT JOIN group_words gw ON gr.id=gw.group_id "\
                  "GROUP BY gr.id");

    while (query.next()) {
        Group* gr = new Group;
        gr->setId(query.value(0).toInt());
        gr->setName(query.value(1).toString());
        gr->setWordCount(query.value(2).toInt());
    }

    return groupList;
}

Word *DbManager::insertWord(const QString &zh, const QString &ru = "", const QString &transcription = "", int status = 0)
{
    QSqlQuery query;
    query.prepare("INSERT INTO word (zh, ru, transcription, status) VALUES (:zh, :ru, :transcription, :status)");
    query.bindValue(":zh", zh);
    query.bindValue(":ru", ru);
    query.bindValue(":transcription", transcription);
    query.bindValue(":status", status);

    if (query.exec()) {
        Word *word = new Word;
        word->setId(query.lastInsertId().toInt());
        word->setZh(zh);
        word->setRu(ru);
        word->setTranscription(transcription);
        word->setStatus(status);

        return word;
    }

    return nullptr;
}

Group *DbManager::insertGroup(const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO groups (name) VALUES ((:name))");
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

Group *DbManager::getOrInsertGroup(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM groups WHERE name=(:name)");
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

Word *DbManager::getOrInsertWord(const QString &zh)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM words WHERE zh=(:zh)");
    query.bindValue(":zh", zh);

    if (query.exec()) {
        if (query.next()) {
            Word* word = new Word;
            word->setId(query.value(0).toInt());
            word->setZh(zh);
            word->setRu(query.value(2).toString());
            word->setTranscription(query.value(3).toString());
            word->setStatus(query.value(4).toInt());

            return word;
        } else {
            Word* word = insertWord(zh);
            return word;
        }
    }

    return nullptr;
}

GroupWord *DbManager::addGroupWord(int groupId, const QString &text)
{
    Word *word = getOrInsertWord(text);
    QSqlQuery query;
    query.prepare("INSERT INTO group_words (group_id, word_id) VALUES (:groupId, :wordId)");
    query.bindValue(":groupId", groupId);
    query.bindValue(":wordId", word->getId());

    if (query.exec()) {

//        GroupWord *groupWord = new GroupWord;
//        groupWord->setWord(word);

//        return groupWord;
    }

    return nullptr;
}

Group *DbManager::updateOrInsertGroup(Group *gr)
{
    QSqlQuery query;
    query.prepare("SELECT 1 FROM groups WHERE id=:id");
    query.bindValue(":id", gr->getId());

    qDebug() << QString("I tut %1 %2").arg((QString)gr->getId(), gr->getName());

    if (query.exec()) {
        qDebug() << "and tut";
        if (query.next()) {
            query.prepare("UPDATE groups SET name=(:name) WHERE id=:id");
            query.bindValue(":id", gr->getId());
            query.bindValue(":name", gr->getName());

            qDebug() << "and and tut";

            if (query.exec()) {
                return gr;
            }
        } else {
            qDebug() << "and tut insert";
            return insertGroup(gr->getName());
        }
    }

    return nullptr;
}

