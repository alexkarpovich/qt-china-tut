#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "LangDao.h"
#include "TranslationDao.h"

TranslationDao::TranslationDao()
{

}

QList<Translation *> TranslationDao::all()
{
    QList<Translation *> list;

    return list;
}

Translation *TranslationDao::get(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM" TRANSLATION_TABLE "WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int trid = query.value(0).toInt();
        int srcid = query.value(1).toInt();
        Language::Code srcCode =  static_cast<Language::Code>(query.value(2).toInt());
        int distid = query.value(3).toInt();
        Language::Code distCode = static_cast<Language::Code>(query.value(4).toInt());
        LangDao ld(srcCode);
        Language *src = ld.get(srcid);
        ld.setCode(distCode);
        Language *dst = ld.get(distid);
        Translation * tr = new Translation;
        tr->setId(trid);
        tr->setSource(src);
        tr->setDist(dst);

        return tr;
    }

    return nullptr;
}

Translation *TranslationDao::create(Translation *value)
{
    QSqlQuery query;
    query.prepare("INSERT INTO" TRANSLATION_TABLE "(src_id, dst_id) VALUES (:srcid, :dstid)");
    query.bindValue(":srcid", value->getSource()->getId());
    query.bindValue(":dstid", value->getDist()->getId());

    if (query.exec() && query.next()) {
        value->setId(query.lastInsertId().toInt());

        return value;
    }

    return nullptr;
}

void TranslationDao::update(Translation *value)
{
    QSqlQuery query;
    query.prepare("UPDATE" TRANSLATION_TABLE "SET src_id=:srcid, dst_id=:dstid WHERE id=:id");
    query.bindValue(":id", value->getId());
    query.bindValue(":srcid", value->getSource()->getId());
    query.bindValue(":dstid", value->getDist()->getId());

    if (query.exec() && query.next()) {
        qDebug() << QString("Translation was updated (%1, %2, %3)")
                    .arg(QString::number(value->getId()), value->getSource()->getId(), value->getDist()->getId());
    } else {
        qDebug() << QString("Translation update error: %s").arg(query.lastError().text());
    }
}

void TranslationDao::del(Translation *value)
{
    QSqlQuery query;
    query.prepare("DELETE FROM" TRANSLATION_TABLE "WHERE id=:id");
    query.bindValue(":id", value->getId());

    if (query.exec() && query.next()) {
        qDebug() << QString("Translation (%1, %2, %3) was deleted")
                    .arg(QString::number(value->getId()), value->getSource()->getId(), value->getDist()->getId());
    } else {
        qDebug() << QString("Group deleting error: %s").arg(query.lastError().text());
    }
}

QList<Translation *> TranslationDao::filterByGroup(int groupid)
{
    QList<Translation *> translations;
    QSqlQuery query;
    query.prepare("SELECT t.* FROM group_translation "
                  "WHERE group_id=:groupid");
    query.bindValue(":groupid", groupid);

    if (query.exec()) {
        while (query.next()) {
            Translation *tr = get(query.value(2).toInt());

            translations << tr;
        }
    }

    return translations;

}
