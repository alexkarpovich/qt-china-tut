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
    query.prepare("SELECT gr.id, gr.name, COUNT(gw.word_id) as word_count FROM groups gr "\
                  "LEFT JOIN group_words gw ON gr.id=gw.group_id "\
                  "GROUP BY gr.id");

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

QList<Word *> DbManager::getAllGroupWords(int groupId)
{
    QSqlQuery query;
    QList<Word*> wordList;
    query.prepare("SELECT w.id, w.zh, w.ru, w.transcription, w.status from words w "\
                  "LEFT JOIN group_words gw ON w.id=gw.word_id "
                  "WHERE gw.group_id=:groupId");
    query.bindValue(":groupId", groupId);

    if (query.exec()) {
        while (query.next()) {
            Word* wrd = new Word;
            wrd->setGroupId(groupId);
            wrd->setId(query.value(0).toInt());
            wrd->setZh(query.value(1).toString());
            wrd->setRu(query.value(2).toString());
            wrd->setTranscription(query.value(3).toString());
            wrd->setStatus(query.value(4).toInt());

            wordList << wrd;
        }
    } else {
        qDebug() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError().number();
    }

    return wordList;
}

Word *DbManager::insertWord(const QString &zh, const QString &ru = "", const QString &transcription = "", int status = Word::StatusNew)
{
    QSqlQuery query;
    query.prepare("INSERT INTO words (zh, ru, transcription, status, updated_at) VALUES (:zh, :ru, :transcription, :status, CURRENT_TIMESTAMP)");
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
    } else {
        qDebug() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError().number();
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

Word *DbManager::insertGroupWord(int groupId, const QString &zh)
{
    Word *wrd = getOrInsertWord(zh);
    QSqlQuery query;
    query.prepare("INSERT INTO group_words (word_id, group_id) VALUES (:wordId, :groupId)");
    query.bindValue(":wordId", wrd->getId());
    query.bindValue(":groupId", groupId);

    if (query.exec()) {
        wrd->setGroupId(groupId);

        return wrd;
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

Word *DbManager::saveGroupWord(int groupId, Word *wrd)
{
    QSqlQuery query;

    if (!groupWordExists(groupId, wrd)) {
        Word *wrd_ = insertGroupWord(groupId, wrd->getZh());
        wrd->setId(wrd_->getId());
    }

    query.prepare("UPDATE words SET zh=:zh, ru=:ru, transcription=:transcription, status=:status WHERE id=:id");
    query.bindValue(":id", wrd->getId());
    query.bindValue(":zh", wrd->getZh());
    query.bindValue(":ru", wrd->getRu());
    query.bindValue(":transcription", wrd->getTranscription());
    query.bindValue(":status", wrd->getStatus());

    if (query.exec()) {
        return wrd;
    }

    return nullptr;
}

bool DbManager::groupWordExists(int groupId, Word *wrd)
{
    QSqlQuery query;
    query.prepare("SELECT 1 FROM group_words gw "
                  "LEFT JOIN words w ON w.id=gw.word_id "
                  "WHERE gw.word_id=:worId AND w.zh=:zh AND gw.group_id=:groupId");
    query.bindValue(":groupId", groupId);
    query.bindValue(":wordId", wrd->getId());
    query.bindValue(":zh", wrd->getZh());

    bool ok = query.exec();
    return ok && query.next();
}

Group *DbManager::saveGroup(Group *gr)
{
    QSqlQuery query;
    query.prepare("SELECT 1 FROM groups WHERE id=:id");
    query.bindValue(":id", gr->getId());

    qDebug() << QString("Saving group(%1, %2)").arg((QString)gr->getId(), gr->getName());

    if (query.exec()) {
        if (query.next()) {
            qDebug() << "Group already exists, updating...";
            query.prepare("UPDATE groups SET name=(:name) WHERE id=:id");
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
    }

    return nullptr;
}
