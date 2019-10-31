#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include <Application.h>
#include <Dao/GroupDao.h>
#include <Dao/WordDao.h>

GroupDao::GroupDao()
{
    profile = qvariant_cast<Profile*>(qGuiApp->property("profile"));
}

QList<Group *> GroupDao::all()
{
    QList<Group *> groups;
    QSqlQuery query;
    query.prepare("SELECT g.id, g.name, COUNT(gw.word_id) as word_count FROM" GROUP_TABLE "g "
                  "LEFT JOIN groups_words gw ON gw.group_id=g.id "
                  "WHERE lang_id=:langid GROUP BY g.id");
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

    if (query.exec()) {
        value->setId(query.lastInsertId().toInt());

        return value;
    }

    return nullptr;
}

Group *GroupDao::create(const QString &name)
{
    Group *gr = new Group;
    gr->setName(name);

    return create(gr);
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
        qDebug() << "Group update error: " + query.lastError().text();
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
        qDebug() << "Group deleting error: " + query.lastError().text();
    }
}

QList<Word *> GroupDao::words(QList<int> groupids)
{
    QList<Word *> list;
    QSqlQuery query;
    QStringList askChars;

    foreach(int id, groupids) {
        askChars << "?";
    }
    QString sql = QString("SELECT w.* FROM %1 w LEFT JOIN groups_words gw ON w.id=gw.word_id WHERE gw.group_id IN (%2)")
        .arg(profile->getLearningLang()->getCode(), askChars.join(","));
    query.prepare(sql);

    foreach(int id, groupids) {
        query.addBindValue(id);
    }

    if (query.exec()) {
        while (query.next()) {
            Word *wrd = new Word;
            wrd->setId(query.value(0).toInt());
            wrd->setText(query.value(1).toString());
            wrd->setTranscription(query.value(2).toString());

            list << wrd;
        }
    } else {
        qDebug() << "Group words error: " + query.lastError().text();
    }

    return list;
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
    query.prepare("INSERT OR IGNORE INTO groups_words (group_id, word_id) VALUES (:groupid, :wordid)");
    query.bindValue(":groupid", groupid);
    query.bindValue(":wordid", wrd->getId());

    if (query.exec()) {
        return wrd;
    } else {
        qDebug() << "Add word to group error: " + query.lastError().text();
    }
}

QMap<int, QString> GroupDao::translationLines(QList<int> groupids)
{
    QSqlQuery query;
    QStringList strnum;
    QMap<int, QString> mapping;

    foreach(int id, groupids) {
        strnum << QString::number(id);
    }

    QString sql = "SELECT t.%1_id, GROUP_CONCAT(r.text, ', ') FROM groups_translations gt "
                  "LEFT JOIN translations t on gt.translation_id = t.id "
                  "LEFT JOIN %2 r on t.%2_id = r.id "
                  "WHERE gt.group_id in (%3) "
                  "GROUP BY t.%1_id";
    sql = sql.arg(profile->getLearningLang()->getCode(),
                  profile->getNativeLang()->getCode(),
                  strnum.join(","));

    if (query.exec(sql)) {
        while (query.next()) {
            mapping[query.value(0).toInt()] = query.value(1).toString();
        }
    } else {
        qDebug() << "Translation lines error: " + query.lastError().text();
    }

    return mapping;
}


