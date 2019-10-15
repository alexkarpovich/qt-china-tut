#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include <Dao/ProfileDao.h>
#include <Dao/LanguageDao.h>

ProfileDao::ProfileDao()
{

}

QList<Profile *> ProfileDao::all()
{
    QList<Profile *> list;

    return list;
}

Profile *ProfileDao::get(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM" PROFILE_TABLE "WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        LanguageDao ld;
        Profile *pr = new Profile;
        pr->setId(query.value(0).toInt());
        pr->setLearningLang(ld.get(query.value(1).toInt()));
        pr->setNativeLang(ld.get(query.value(2).toInt()));

        return pr;
    }

    return nullptr;
}

Language *ProfileDao::create(Profile *value)
{
    return nullptr;
}

void ProfileDao::update(Profile *value)
{

}

void ProfileDao::del(Profile *value)
{

}
