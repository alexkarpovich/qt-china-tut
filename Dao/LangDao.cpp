#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "LangDao.h"

LangDao::LangDao(const Language::Code &code)
{
    this->code = code;
}

void LangDao::setCode(const Language::Code &value)
{
    code = value;
}

QList<Language *> LangDao::all()
{
    QList<Language *> langs;
    QSqlQuery query;
    QString table = Language::codeString(code);
    query.prepare("SELECT * FROM "+ table);

    if (query.exec()) {
        while (query.next()) {
            Language* lng = new Language;
            lng->setId(query.value(0).toInt());
            lng->setWord(query.value(1).toString());
            lng->setTranscription(query.value(2).toString());
            langs << lng;
        }
    }



    return langs;
}

Language *LangDao::get(int id)
{
    QSqlQuery query;
    QString table = Language::codeString(code);
    query.prepare("SELECT * FROM " + table + " WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        Language* lng = new Language;
        lng->setId(query.value(0).toInt());
        lng->setWord(query.value(1).toString());
        lng->setTranscription(query.value(2).toString());

        return lng;
    }

    return nullptr;
}

Language *LangDao::create(Language *value)
{
    QSqlQuery query;
    QString table = Language::codeString(code);
    query.prepare("INSERT INTO " + table + " (word, transcription) VALUES ((:word), (:transcription))");
    query.bindValue(":name", value->getWord());
    query.bindValue(":transcription", value->getTranscription());

    if (query.exec() && query.next()) {
        value->setId(query.lastInsertId().toInt());

        return value;
    }

    return nullptr;
}

void LangDao::update(Language *value)
{
    QSqlQuery query;
    QString table = Language::codeString(code);
    query.prepare("UPDATE" + table + "SET word=:word, transcription=:transcription WHERE id=:id");
    query.bindValue(":id", value->getId());
    query.bindValue(":word", value->getWord());
    query.bindValue(":transcription", value->getTranscription());

    if (query.exec() && query.next()) {
        qDebug() << QString("Lang was updated (%1, %2)").arg(QString::number(value->getId()), value->getWord());
    } else {
        qDebug() << QString("Lang update error: %s").arg(query.lastError().text());
    }
}

void LangDao::del(Language *value)
{
    QSqlQuery query;
    QString table = Language::codeString(code);

    query.prepare("DELETE FROM" + table + "WHERE id=:id");
    query.bindValue(":id", value->getId());

    if (query.exec() && query.next()) {
        qDebug() << QString("Group (%1, %2) was deleted").arg(QString::number(value->getId()), value->getWord());
    } else {
        qDebug() << QString("Group deleting error: %s").arg(query.lastError().text());
    }
}
