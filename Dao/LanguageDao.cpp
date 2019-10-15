#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include <Dao/LanguageDao.h>

LanguageDao::LanguageDao()
{

}

QList<Language *> LanguageDao::all()
{
    QList<Language *> list;

    return list;
}

Language *LanguageDao::get(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM" LANGUAGE_TABLE "WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        Language* lng = new Language;
        lng->setId(query.value(0).toInt());
        lng->setCode(query.value(1).toString());
        lng->setName(query.value(2).toString());

        return lng;
    }

    return nullptr;
}

Language *LanguageDao::create(Language *value)
{
    return nullptr;
}

void LanguageDao::update(Language *value)
{

}

void LanguageDao::del(Language *value)
{

}
